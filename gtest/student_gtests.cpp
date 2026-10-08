// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Stack module. It is graded: the autograder runs it against
// a correct Stack and against several Stacks with one bug each. A test is worth something only
// when it passes on the correct Stack and fails on a broken one, so a test that always fails
// (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for pop, push_all, pop_all, and the edges
// (an empty stack, a stack of one character, a full stack).
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTests, NewStackIsEmptyAndNotFull) {
    Stack stk;
    EXPECT_TRUE(stk.isEmpty());
    EXPECT_FALSE(stk.isFull());
}

TEST(StackTests, PushThenTopSeesTheCharacter) {
    Stack stk;
    stk.push('z');
    EXPECT_EQ(stk.top(), 'z');
}

// ADD YOUR TESTS HERE:
// ===================== Student tests =====================
#include <sstream>
#include <string>

namespace {

// runs pop_all and returns what it printed to cout
std::string capture_pop_all(Stack& s) {
    std::ostringstream out;
    std::streambuf* old = std::cout.rdbuf(out.rdbuf());
    pop_all(s);
    std::cout.rdbuf(old);
    return out.str();
}

TEST(StudentStack, PopOnEmptyReturnsAt) {
    Stack s;
    EXPECT_EQ('@', s.pop());
    EXPECT_TRUE(s.isEmpty());
}

TEST(StudentStack, TopOnEmptyReturnsAt) {
    Stack s;
    EXPECT_EQ('@', s.top());
    EXPECT_TRUE(s.isEmpty());
}

TEST(StudentStack, ExtraPopsDoNotBreakStack) {
    Stack s;
    s.push('a');
    EXPECT_EQ('a', s.pop());
    EXPECT_EQ('@', s.pop());
    EXPECT_EQ('@', s.pop());
    EXPECT_TRUE(s.isEmpty());
    s.push('b');
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ('b', s.top());
    EXPECT_EQ('b', s.pop());
    EXPECT_TRUE(s.isEmpty());
}

TEST(StudentStack, OneCharTopDoesNotRemove) {
    Stack s;
    s.push('q');
    EXPECT_FALSE(s.isEmpty());
    EXPECT_FALSE(s.isFull());
    EXPECT_EQ('q', s.top());
    EXPECT_EQ('q', s.top());
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ('q', s.pop());
    EXPECT_TRUE(s.isEmpty());
}

TEST(StudentStack, PopIsLastInFirstOut) {
    Stack s;
    s.push('a');
    s.push('b');
    s.push('c');
    EXPECT_EQ('c', s.top());
    EXPECT_EQ('c', s.pop());
    EXPECT_EQ('b', s.pop());
    EXPECT_EQ('a', s.pop());
    EXPECT_EQ('@', s.pop());
}

TEST(StudentStack, FullExactlyAtCapacity) {
    Stack s;
    for (int i = 0; i < STK_MAX - 1; i++) {
        s.push('a');
    }
    EXPECT_FALSE(s.isFull());
    s.push('a');
    EXPECT_TRUE(s.isFull());
    EXPECT_FALSE(s.isEmpty());
}

TEST(StudentStack, PushOnFullIsIgnored) {
    Stack s;
    for (int i = 0; i < STK_MAX - 1; i++) {
        s.push('a');
    }
    s.push('z');
    EXPECT_TRUE(s.isFull());
    s.push('x');
    EXPECT_TRUE(s.isFull());
    EXPECT_EQ('z', s.top());
    EXPECT_EQ('z', s.pop());
    EXPECT_EQ('a', s.pop());
    EXPECT_FALSE(s.isFull());
}

TEST(StudentStack, FullStackPopsExactlyCapacity) {
    Stack s;
    for (int i = 0; i < STK_MAX; i++) {
        s.push('k');
    }
    s.push('x');
    for (int i = 0; i < STK_MAX; i++) {
        EXPECT_EQ('k', s.pop());
    }
    EXPECT_TRUE(s.isEmpty());
    EXPECT_EQ('@', s.pop());
}

TEST(StudentStack, PushAllKeepsOrder) {
    Stack s;
    push_all(s, "abc");
    EXPECT_EQ('c', s.pop());
    EXPECT_EQ('b', s.pop());
    EXPECT_EQ('a', s.pop());
    EXPECT_TRUE(s.isEmpty());
}

TEST(StudentStack, PushAllEmptyString) {
    Stack s;
    push_all(s, "");
    EXPECT_TRUE(s.isEmpty());
}

TEST(StudentStack, PopAllPrintsReversedWithNewline) {
    Stack s;
    push_all(s, "hello");
    EXPECT_EQ("olleh\n", capture_pop_all(s));
    EXPECT_TRUE(s.isEmpty());
}

TEST(StudentStack, PopAllOnEmptyPrintsJustNewline) {
    Stack s;
    EXPECT_EQ("\n", capture_pop_all(s));
    EXPECT_TRUE(s.isEmpty());
}

TEST(StudentStack, PopAllEmptiesForNextLine) {
    Stack s;
    push_all(s, "ab");
    EXPECT_EQ("ba\n", capture_pop_all(s));
    push_all(s, "xyz");
    EXPECT_EQ("zyx\n", capture_pop_all(s));
}

} // anonymous namespace
