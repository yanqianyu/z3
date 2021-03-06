/*++
Copyright (c) 2012 Microsoft Corporation

Module Name:

    tactic_manager.h

Abstract:
    Collection of tactics & probes

Author:

    Leonardo (leonardo) 2012-03-06

Notes:

--*/
#pragma once

#include "cmd_context/tactic_cmds.h"
#include "util/dictionary.h"

class tactic_manager {
protected:
    dictionary<tactic_cmd*>  m_name2tactic;
    dictionary<probe_info*>  m_name2probe;
    ptr_vector<tactic_cmd>   m_tactics;
    ptr_vector<probe_info>   m_probes;
    void finalize_tactic_cmds();
    void finalize_probes();
public:
    ~tactic_manager();

    void insert(tactic_cmd * c);
    void insert(probe_info * p);
    tactic_cmd * find_tactic_cmd(symbol const & s) const; 
    probe_info * find_probe(symbol const & s) const; 

    unsigned num_tactics() const { return m_tactics.size(); }
    unsigned num_probes() const { return m_probes.size(); }
    tactic_cmd * get_tactic(unsigned i) const { return m_tactics[i]; }
    probe_info * get_probe(unsigned i) const { return m_probes[i]; }
    
    typedef ptr_vector<tactic_cmd>::const_iterator tactic_cmd_iterator;
    tactic_cmd_iterator begin_tactic_cmds() const { return m_tactics.begin(); }
    tactic_cmd_iterator end_tactic_cmds() const { return m_tactics.end(); }
    class tactics_iterator {
        tactic_manager const& m;
    public:
        tactics_iterator(tactic_manager const& m):m(m) {}
        tactic_cmd_iterator begin() const { return m.begin_tactic_cmds(); }
        tactic_cmd_iterator end() const { return m.end_tactic_cmds(); }
    };
    tactics_iterator tactics() const { return tactics_iterator(*this); }

    typedef ptr_vector<probe_info>::const_iterator probe_iterator;
    probe_iterator begin_probes() const { return m_probes.begin(); }
    probe_iterator end_probes() const { return m_probes.end(); }

    class probes_iterator {
        tactic_manager const& m;
    public:
        probes_iterator(tactic_manager const& m):m(m) {}
        probe_iterator begin() const { return m.begin_probes(); }
        probe_iterator end() const { return m.end_probes(); }
    };

    probes_iterator probes() const { return probes_iterator(*this); }
        
};




