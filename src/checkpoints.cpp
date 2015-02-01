// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double fSigcheckVerificationFactor = 5.0;

    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64 nTimeLastCheckpoint;
        int64 nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (      1, uint256("0x20ba7c3117bdc6ed4f9ed9056604a22353aabdf9404a7110a162f3be939e2365"))
		(   1000, uint256("0x9547cf9c731e3b28729f503a66cc876328eb8fa8c81f4269e7ee003e3c3fe7b3"))
		(   2000, uint256("0x0e9a39fc44c6bb4771a5e0c4990049aec9596857392e1671f407bcb3efd13e90"))
        (   3000, uint256("0x5fd2927fcdbe2e07fac5588d07432e9fa1af8902afc960a66da870789d5a372d"))
        (   4000, uint256("0x0f0c26603474d02b9bf706cba198a7447589e0b10bbe5caa415e5f9f81ae71ab"))
        (   5000, uint256("0x39ee78b8d80f850f0603ac98c888f31cb287e9f9ddddcf2fe0dc04b2e44b4fc3"))
        (   6000, uint256("0xd1ae019feb27291270bcad2ef895e8e2a207e3fa187d20e1cf2de0e4457239d5"))
        (   7000, uint256("0xc4343e7858f07f9b16cae09418343e5491a3c394afde1bb83acd7c8222a81d0f"))
        (   8000, uint256("0x78449e84bf1521e3ee84159bb2e87c7ee0961613c56f0cde7ffa3dcc0d885653"))
        (   9000, uint256("0x9967659ad9151bb143fdc32e2ac85513e898a4e82c88efd0f0787098cb21604f"))
        (   9056, uint256("0x13d95ff35dac19627bbb6c6df36d785196c531bda635ce77f30c2ec60c4a3086"))
        (  10000, uint256("0xd6f11f83be09a80717036a9f85fd3c487d97f924f01ef3bd244e9b2786664ebb"))
        (  20000, uint256("0xfba9553f09f45e9dbbd8189ca63278d4b0ee8ba9a75d477da5e25dd034f4a0d3"))
        (  30000, uint256("0x28a0d5985b11321836ebb841e675e6e197c3dc934027d1d19f821708094d6721"))
        (  40000, uint256("0x415e8ef92e21899fab952b67f1bc1e336367d35a905b8bbe5b3c8f741237703d"))
        (  50000, uint256("0x1abbfb14e47ae45f39df10403f80d5425857b4be1645eabb899ea0d054ec5c82"))
        (  60000, uint256("0x57b9dc1701d4879fc15c631bfcb982c73a4e1f1d6e619dfcd2b7760635ea55a1"))
        (  64430, uint256("0x564d94d38b108bc6c9e7b59fa33b547f094da01a099b87af6601e8d3e30cb2c3"))
        (  70000, uint256("0xc4b7e6c121e5c3ca3619206d1d16cffca3ffa8478629ecdf4e2b094f71f52788"))
        (  72250, uint256("0x9a21343776ca06e1f3e28701e4c220495623bea97f102b464ea875b3cd348b58"))
        (  87775, uint256("0xbb48680669b4c7b8da1d55169ffc0fad87aed3ed5437c56bfa32b20fa6a60f07"))
        (  95525, uint256("0x249ad68be80ac0a8077150a21d1e3f8def5dc5a65e24f0bf2b7c5e7db1983e7b"))
        (  96846, uint256("0x3a08388e78ddca11fc0832214d7529e57c794cfa3e3175f170b72f415aaf4833"))
        ( 101864, uint256("0x1c7f2129bbdc260abd6b7a04ccb0baff03f204e8ad72be57ea8cbedd8f177e9b"))
        ;
    static const CCheckpointData data = {
        &mapCheckpoints,
        1422730957, // * UNIX timestamp of last checkpoint block
        188514,    // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        7000.0     // * estimated number of transactions per day after checkpoint
    };

    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        (   546, uint256("000000002a936ca763904c3c35fce2f3556c559c0214345d31b1bcebf76acb70"))
        ( 35000, uint256("2af959ab4f12111ce947479bfcef16702485f04afd95210aa90fde7d1e4a64ad"))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1369685559,
        37581,
        300
    };

    const CCheckpointData &Checkpoints() {
        if (fTestNet)
            return dataTestnet;
        else
            return data;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (!GetBoolArg("-checkpoints", true))
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex) {
        if (pindex==NULL)
            return 0.0;

        int64 nNow = time(NULL);

        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (!GetBoolArg("-checkpoints", true))
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (!GetBoolArg("-checkpoints", true))
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
