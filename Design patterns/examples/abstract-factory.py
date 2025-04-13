#!/usr/bin/env python3

import abc


class CrutchBase(abc.ABC):
    @abc.abstractmethod
    def hack(self):
        pass


class CrutchA(CrutchBase):
    def hack(self):
        print("Hack the problem via the A approach")


class CrutchB(CrutchBase):
    def hack(self):
        print("Hack the problem via the B approach")


class BicycleBase(abc.ABC):
    @abc.abstractmethod
    def workaround(self):
        pass


class BicycleA(BicycleBase):
    def workaround(self):
        print("Workaround the problem via the A approach")


class BicycleB(BicycleBase):
    def workaround(self):
        print("Workaround the problem via the B approach")


class IssueFactory(abc.ABC):
    @abc.abstractmethod
    def fix_bugs(self):
        pass


class IssueA(IssueFactory):
    def fix_bugs(self):
        BicycleA().workaround()
        CrutchA().hack()


class IssueB(IssueFactory):
    def fix_bugs(self):
        BicycleB().workaround()
        CrutchB().hack()


class IssueSolver:
    @classmethod
    def run(cls, issue: IssueFactory):
        issue().fix_bugs()


IssueSolver.run(IssueA)
# Workaround the problem via the A approach
# Hack the problem via the A approach
IssueSolver.run(IssueB)
# Workaround the problem via the B approach
# Hack the problem via the B approach
