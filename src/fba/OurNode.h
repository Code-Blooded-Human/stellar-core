#ifndef __OURNODE__
#define __OURNODE__

// Copyright 2014 Stellar Development Foundation and contributors. Licensed
// under the ISC License. See the COPYING file at the top-level directory of
// this distribution or at http://opensource.org/licenses/ISC

#include <chrono>
#include "fba/Node.h"
#include "fba/Statement.h"
#include "fba/QuorumSet.h"

using namespace std;

namespace stellar
{
class Application;

class OurNode : public Node
{
    Application& mApp;
    chrono::system_clock::time_point
        mTimeSent[FBAStatementType::UNKNOWN];

    SlotBallot mPreferredBallot;

    void sendNewPrepare(QuorumSet::pointer qset);

    void setPending(Statement::pointer pending);
    void progressPrepare(QuorumSet::pointer);
    void progressPrepared(QuorumSet::pointer);
    void progressCommit(QuorumSet::pointer);
    void progressCommitted(QuorumSet::pointer);

    void sendStatement(FBAStatementType type,
                       const SlotBallot& ballot);

    BallotPtr whatRatified(FBAStatementType type);

  public:
    typedef std::shared_ptr<OurNode> pointer;

    OurNode(Application& app);

    void startNewRound(const SlotBallot& firstBallot);

    void progressFBA();
};
}

#endif
