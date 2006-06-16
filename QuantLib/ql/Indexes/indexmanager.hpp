/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2004, 2005, 2006 StatPro Italia srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/reference/license.html>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file indexmanager.hpp
    \brief global repository for past index fixings
*/

#ifndef quantlib_index_manager_hpp
#define quantlib_index_manager_hpp

#include <ql/history.hpp>
#include <ql/Patterns/singleton.hpp>
#include <ql/Utilities/observablevalue.hpp>
#include <map>

namespace QuantLib {

    //! global repository for past index fixings
    class IndexManager : public Singleton<IndexManager> {
        friend class Singleton<IndexManager>;
      private:
        IndexManager() {}
      public:
        //! returns whether historical fixings were stored for the index
        bool hasHistory(const std::string& name) const;
        //! returns the (possibly empty) history of the index fixings
        const History& getHistory(const std::string& name) const;
        //! stores the historical fixings of the index
        void setHistory(const std::string& name, const History&);
        //! observer notifying of changes in the index fixings
        boost::shared_ptr<Observable> notifier(const std::string& name) const;
        //! returns all names of the indexes for which fixings were stored
        std::vector<std::string> histories() const;
        //! clears all stored fixings
        void clearHistories();
      private:
        mutable std::map<std::string, ObservableValue<History> > data_;
    };

}


#endif
