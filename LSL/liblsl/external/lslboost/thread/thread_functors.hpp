// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.lslboost.org/LICENSE_1_0.txt)
// (C) Copyright 2009-2012 Anthony Williams
// (C) Copyright 2012 Vicente J. Botet Escriba

// Based on the Anthony's idea of scoped_thread in CCiA

#ifndef BOOST_THREAD_THREAD_FUNCTORS_HPP
#define BOOST_THREAD_THREAD_FUNCTORS_HPP

#include <lslboost/thread/detail/config.hpp>
#include <lslboost/thread/detail/delete.hpp>
#include <lslboost/thread/detail/move.hpp>
#include <lslboost/thread/thread_only.hpp>

#include <lslboost/config/abi_prefix.hpp>

namespace lslboost
{

  struct detach
  {
    void operator()(thread& t)
    {
      t.detach();
    }
  };

  struct join_if_joinable
  {
    void operator()(thread& t)
    {
      if (t.joinable())
      {
        t.join();
      }
    }
  };

#if defined BOOST_THREAD_PROVIDES_INTERRUPTIONS
  struct interrupt_and_join_if_joinable
  {
    void operator()(thread& t)
    {
      t.interrupt();
      if (t.joinable())
      {
        t.join();
      }
    }
  };
#endif
}
#include <lslboost/config/abi_suffix.hpp>

#endif
