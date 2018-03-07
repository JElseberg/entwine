/******************************************************************************
* Copyright (c) 2016, Connor Manning (connor@hobu.co)
*
* Entwine -- Point cloud indexing
*
* Entwine is available under the terms of the LGPL2 license. See COPYING
* for specific license text and more information.
*
******************************************************************************/

/*
#include <entwine/tree/clipper.hpp>

#include <entwine/tree/climber.hpp>

namespace entwine
{

bool Clipper::insert(const Id& chunkId, std::size_t chunkNum, std::size_t depth)
{
    assert(depth >= m_startDepth);
    depth -= m_startDepth;

    if (depth < m_fastCache.size())
    {
        auto& it(m_fastCache[depth]);

        if (it != m_clips.end() && it->first == chunkId)
        {
            it->second.fresh = true;
            m_order.splice(
                    m_order.begin(),
                    m_order,
                    *it->second.orderIt);

            return false;
        }
    }

    auto it(m_clips.find(chunkId));

    if (it != m_clips.end())
    {
        if (depth < m_fastCache.size()) m_fastCache[depth] = it;

        it->second.fresh = true;
        m_order.splice(
                m_order.begin(),
                m_order,
                *it->second.orderIt);

        return false;
    }
    else
    {
        it = m_clips.insert(
                    std::make_pair(chunkId, ClipInfo(chunkNum))).first;

        m_order.push_front(it);
        it->second.orderIt =
            makeUnique<ClipInfo::Order::iterator>(m_order.begin());

        if (depth < m_fastCache.size()) m_fastCache[depth] = it;

        return true;
    }
}

void Clipper::clip()
{
    if (m_clips.size() < heuristics::clipcachesize) return;

    m_fastcache.assign(32, m_clips.end());
    bool done(false);

    while (m_clips.size() > heuristics::clipcachesize && !done)
    {
        clipinfo::map::iterator& it(*m_order.rbegin());

        if (!it->second.fresh)
        {
            // m_builder.clip(it->first, it->second.chunknum, m_id);
            m_clips.erase(it);
            m_order.pop_back();
        }
        else
        {
            done = true;
        }
    }

    for (auto& p : m_clips) p.second.fresh = false;
}

} // namespace entwine
*/

