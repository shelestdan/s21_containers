#include <gtest/gtest.h>
#include <s21_containers.h>
#include <s21_containersplus.h>

#include <list>
#include <queue>
#include <stack>
#include <vector>
namespace s21 {
// >>>>>>> VECTOR <<<<<<<<

class Test_vector {
 public:
  s21::vector<int> empty_Vector;
  s21::vector<int> five_Vector{1, 2, 3, 4, 5};
  s21::vector<int> four_Vector{1, 2, 3, 4};
  s21::vector<char> char_Vector;
  s21::vector<float> float_Vector;
  s21::vector<double> double_Vector;
  std::vector<int> origin_five_vector{1, 2, 3, 4, 5};
  std::vector<int> origin_four_vector{1, 2, 3, 4};
  std::vector<int> origin_int;
  std::vector<char> origin_char;
  std::vector<float> origin_float;
  std::vector<double> origin_double;
  std::vector<int>::iterator it_origin = origin_five_vector.begin();
  s21::vector<int> s21_vector_lesser{534789,   2479056, 987654, 110101024,
                                     62348710, 1,       35674};
  std::vector<int> std_vector_lesser{534789,   2479056, 987654, 110101024,
                                     62348710, 1,       35674};
  s21::vector<int> s21_vector_copy_lesser{1, 2};
  std::vector<int> std_vector_copy_lesser{1, 2};
  s21::vector<int> s21_vector_copy_larger{9, 8, 7, 6, 5, 4, 3};
  std::vector<int> std_vector_copy_larger{9, 8, 7, 6, 5, 4, 3};
  s21::vector<int> s21_vector_larger{1, 2};
  std::vector<int> std_vector_larger{1, 2};
  s21::vector<int> s21_vector_ass{-333, -999, 123, 11765, 3};
  std::vector<int> std_vector_ass{-333, -999, 123, 11765, 3};
  s21::vector<int> s21_vector_move{1, 2};
  std::vector<int> std_vector_move{1, 2};
  s21::vector<int> s21_vector_s{111, 222, 333, 444, 555};
  std::vector<int> std_vector_s{111, 222, 333, 444, 555};
  s21::vector<int> s21_vector_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> std_vector_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
};

TEST(Vector, constructor_default) {
  Test_vector logger;
  EXPECT_EQ(logger.empty_Vector.size(), logger.origin_int.size());
  EXPECT_EQ(logger.empty_Vector.capacity(), logger.origin_int.capacity());
  EXPECT_EQ(logger.empty_Vector.empty(), logger.origin_int.empty());
}

TEST(Vector, constructor_init) {
  s21::vector<int> s21_vector(3);
  std::vector<int> std_vector(3);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, constructor_initializer_lit) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector[0], logger.origin_five_vector[0]);
  EXPECT_EQ(logger.five_Vector[4], logger.origin_five_vector[4]);
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.empty(), logger.origin_five_vector.empty());
}

TEST(Vector, constructor_copy_empty) {
  Test_vector logger;
  s21::vector<int> s21_copy(logger.empty_Vector);
  std::vector<int> std_copy(logger.origin_int);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, constructor_copy_not_empty) {
  Test_vector logger;
  s21::vector<int> s21_copy(logger.five_Vector);
  std::vector<int> std_copy(logger.origin_five_vector);
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, constructor_move_not_empty) {
  Test_vector logger;
  s21::vector<int> s21_copy(std::move(logger.five_Vector));
  std::vector<int> std_copy(std::move(logger.origin_five_vector));
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, constructor_move_empty) {
  Test_vector logger;
  s21::vector<int> s21_copy(std::move(logger.empty_Vector));
  std::vector<int> std_copy(std::move(logger.origin_int));
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, operator_copy_empty) {
  Test_vector logger;
  s21::vector<int> s21_copy(logger.empty_Vector);
  std::vector<int> std_copy(logger.origin_int);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, operator_copy_not_empty) {
  Test_vector logger;
  s21::vector<int> s21_copy(logger.five_Vector);
  std::vector<int> std_copy(logger.origin_five_vector);
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, operator_move_not_empty) {
  Test_vector logger;
  s21::vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = std::move(logger.five_Vector);
  std_copy = std::move(logger.origin_five_vector);
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, operator_move_empty) {
  Test_vector logger;
  s21::vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = std::move(logger.empty_Vector);
  std_copy = std::move(logger.origin_int);

  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(Vector, copy_assignment_lesser_buffer) {
  Test_vector logger;
  logger.s21_vector_copy_lesser = logger.s21_vector_lesser;
  logger.std_vector_copy_lesser = logger.std_vector_lesser;
  EXPECT_EQ(logger.s21_vector_copy_lesser[0], logger.std_vector_copy_lesser[0]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[1], logger.std_vector_copy_lesser[1]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[2], logger.std_vector_copy_lesser[2]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[3], logger.std_vector_copy_lesser[3]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[4], logger.std_vector_copy_lesser[4]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[5], logger.std_vector_copy_lesser[5]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[6], logger.std_vector_copy_lesser[6]);
  EXPECT_EQ(logger.s21_vector_copy_lesser.size(),
            logger.std_vector_copy_lesser.size());
  EXPECT_EQ(logger.s21_vector_copy_lesser.capacity(),
            logger.std_vector_copy_lesser.capacity());
  EXPECT_EQ(logger.s21_vector_copy_lesser.empty(),
            logger.std_vector_copy_lesser.empty());
}

TEST(Vector, copy_assignment_larger_buffer) {
  Test_vector logger;
  logger.s21_vector_copy_larger = logger.s21_vector_copy_larger;
  logger.std_vector_copy_larger = logger.std_vector_copy_larger;
  EXPECT_EQ(logger.s21_vector_copy_larger[0], logger.std_vector_copy_larger[0]);
  EXPECT_EQ(logger.s21_vector_copy_larger[1], logger.std_vector_copy_larger[1]);
  EXPECT_EQ(logger.s21_vector_copy_larger.size(),
            logger.std_vector_copy_larger.size());
  EXPECT_EQ(logger.s21_vector_copy_larger.capacity(),
            logger.std_vector_copy_larger.capacity());
  EXPECT_EQ(logger.s21_vector_copy_larger.empty(),
            logger.std_vector_copy_larger.empty());
}

TEST(Vector, move_assigment) {
  Test_vector logger;
  logger.s21_vector_move = std::move(logger.s21_vector_ass);
  logger.std_vector_move = std::move(logger.std_vector_ass);
  EXPECT_EQ(logger.s21_vector_move[0], logger.std_vector_move[0]);
  EXPECT_EQ(logger.s21_vector_move[1], logger.std_vector_move[1]);
  EXPECT_EQ(logger.s21_vector_move[2], logger.std_vector_move[2]);
  EXPECT_EQ(logger.s21_vector_move[3], logger.std_vector_move[3]);
  EXPECT_EQ(logger.s21_vector_move[4], logger.std_vector_move[4]);
  EXPECT_EQ(logger.s21_vector_move.size(), logger.std_vector_move.size());
  EXPECT_EQ(logger.s21_vector_move.capacity(),
            logger.std_vector_move.capacity());
  EXPECT_EQ(logger.s21_vector_move.empty(), logger.std_vector_move.empty());
  EXPECT_EQ(logger.s21_vector_ass.size(), logger.std_vector_ass.size());
  EXPECT_EQ(logger.s21_vector_ass.capacity(), logger.std_vector_ass.capacity());
  EXPECT_EQ(logger.s21_vector_ass.empty(), logger.std_vector_ass.empty());
}

TEST(Vector, function_at) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector.at(0), logger.origin_five_vector.at(0));
  EXPECT_EQ(logger.five_Vector.at(1), logger.origin_five_vector.at(1));
  EXPECT_EQ(logger.five_Vector.at(2), logger.origin_five_vector.at(2));
  EXPECT_EQ(logger.five_Vector.at(3), logger.origin_five_vector.at(3));
}

TEST(Vector, operator_square) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector[0], logger.origin_five_vector[0]);
  EXPECT_EQ(logger.five_Vector[1], logger.origin_five_vector[1]);
  EXPECT_EQ(logger.five_Vector[2], logger.origin_five_vector[2]);
  EXPECT_EQ(logger.five_Vector[3], logger.origin_five_vector[3]);
}

TEST(Vector, function_front) {
  Test_vector logger;
  EXPECT_EQ(logger.origin_five_vector.front(), logger.five_Vector.front());
}

TEST(Vector, function_back) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector.back(), logger.origin_five_vector.back());
}

TEST(Vector, iterator_element_access) {
  s21::vector<char> s21_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  std::vector<char> std_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  s21::vector<char>::iterator s21_it = s21_vector.begin();
  std::vector<char>::iterator std_it = std_vector.begin();
  while (s21_it != s21_vector.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(vector_iterator_suit, const_iterator_element_access) {
  s21::vector<char> s21_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  std::vector<char> std_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  s21::vector<char>::const_iterator s21_it = s21_vector.begin();
  std::vector<char>::const_iterator std_it = std_vector.begin();
  while (s21_it != s21_vector.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(Vector, function_data) {
  Test_vector logger;
  EXPECT_EQ(*logger.five_Vector.data(), *logger.origin_five_vector.data());
}

TEST(Vector, function_data_e) {
  s21::vector<char> s21_vector_empty;
  std::vector<char> std_vector_empty;
  EXPECT_EQ(s21_vector_empty.data(), nullptr);
  EXPECT_EQ(std_vector_empty.data(), nullptr);
  s21::vector<char> s21_vector{'L', 'I', 'Z', 'A'};
  std::vector<char> std_vector{'L', 'I', 'Z', 'A'};
  EXPECT_NE(s21_vector.data(), nullptr);
  EXPECT_NE(std_vector.data(), nullptr);
}

TEST(Vector, function_insert_begin) {
  s21::vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_insert_mid) {
  s21::vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_insert_end) {
  s21::vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::vector<int>::iterator s21_it = s21_vector.end();
  std::vector<int>::iterator std_it = std_vector.end();
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_insert_multi) {
  s21::vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = s21_vector.insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.at(7), std_vector.at(7));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_erase_begin) {
  s21::vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_erase_mid) {
  s21::vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_erase_end) {
  s21::vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::vector<int>::iterator s21_it = s21_vector.end() - 1;
  std::vector<int>::iterator std_it = std_vector.end() - 1;
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_erase_multi) {
  s21::vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::vector<int>::iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  s21_it = s21_vector.begin();
  std_it = std_vector.begin();
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, empty_testing) {
  Test_vector logger;
  EXPECT_FALSE(logger.five_Vector.empty());
  EXPECT_TRUE(logger.empty_Vector.empty());
}

TEST(Vector, size_testing) {
  Test_vector logger;
  EXPECT_EQ(logger.empty_Vector.size(), 0);
  EXPECT_EQ(logger.five_Vector.size(), 5);
}

TEST(Vector, max_size_testing) {
  Test_vector logger;
  EXPECT_EQ(logger.empty_Vector.max_size(), logger.origin_int.max_size());
  EXPECT_EQ(logger.char_Vector.max_size(), logger.origin_char.max_size());
  EXPECT_EQ(logger.float_Vector.max_size(), logger.origin_float.max_size());
  EXPECT_EQ(logger.double_Vector.max_size(), logger.origin_double.max_size());
}

TEST(Vector, reserve_testing) {
  Test_vector logger;
  logger.five_Vector.reserve(2);
  logger.origin_five_vector.reserve(2);
  logger.five_Vector.reserve(1000);
  logger.origin_five_vector.reserve(1000);
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.reserve(0);
  logger.origin_five_vector.reserve(0);
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  //        EXPECT_ANY_THROW(logger.five_Vector.reserve(-1));  // google leaks
}

TEST(Vector, capacity_testing) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.push_back(3);
  logger.origin_five_vector.push_back(4);
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.pop_back();
  logger.origin_five_vector.pop_back();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
}

TEST(Vector, shrink_to_fit_testing) {
  Test_vector logger;
  logger.five_Vector.reserve(3);
  logger.origin_five_vector.reserve(3);
  logger.five_Vector.shrink_to_fit();
  logger.origin_five_vector.shrink_to_fit();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
  logger.five_Vector.reserve(100);
  logger.origin_five_vector.reserve(100);
  logger.five_Vector.shrink_to_fit();
  logger.origin_five_vector.shrink_to_fit();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
  logger.five_Vector.reserve(0);
  logger.origin_five_vector.reserve(0);
  logger.five_Vector.shrink_to_fit();
  logger.origin_five_vector.shrink_to_fit();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
}

TEST(Vector, clear_testing) {
  Test_vector logger;
  logger.five_Vector.clear();
  logger.origin_five_vector.clear();
  EXPECT_EQ(logger.five_Vector.capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.size(), logger.origin_five_vector.size());
}

TEST(Vector, function_swap) {
  Test_vector logger;
  logger.s21_vector_s.swap(logger.s21_vector_swap);
  logger.std_vector_s.swap(logger.std_vector_swap);
  EXPECT_EQ(logger.s21_vector_swap.at(0), logger.std_vector_swap.at(0));
  EXPECT_EQ(logger.s21_vector_swap.at(1), logger.std_vector_swap.at(1));
  EXPECT_EQ(logger.s21_vector_swap.at(2), logger.std_vector_swap.at(2));
  EXPECT_EQ(logger.s21_vector_swap.at(3), logger.std_vector_swap.at(3));
  EXPECT_EQ(logger.s21_vector_swap.at(4), logger.std_vector_swap.at(4));
  EXPECT_EQ(logger.s21_vector_swap.size(), logger.std_vector_swap.size());
  EXPECT_EQ(logger.s21_vector_swap.capacity(),
            logger.std_vector_swap.capacity());
  EXPECT_EQ(logger.std_vector_s.at(0), logger.std_vector_s.at(0));
  EXPECT_EQ(logger.std_vector_s.at(1), logger.std_vector_s.at(1));
  EXPECT_EQ(logger.std_vector_s.at(2), logger.std_vector_s.at(2));
  EXPECT_EQ(logger.std_vector_s.at(3), logger.std_vector_s.at(3));
  EXPECT_EQ(logger.std_vector_s.at(4), logger.std_vector_s.at(4));
  EXPECT_EQ(logger.std_vector_s.at(5), logger.std_vector_s.at(5));
  EXPECT_EQ(logger.std_vector_s.at(6), logger.std_vector_s.at(6));
  EXPECT_EQ(logger.std_vector_s.at(7), logger.std_vector_s.at(7));
  EXPECT_EQ(logger.std_vector_s.at(8), logger.std_vector_s.at(8));
  EXPECT_EQ(logger.std_vector_s.at(9), logger.std_vector_s.at(9));
  EXPECT_EQ(logger.std_vector_s.size(), logger.std_vector_s.size());
  EXPECT_EQ(logger.std_vector_s.capacity(), logger.std_vector_s.capacity());
  EXPECT_EQ(logger.std_vector_s.empty(), logger.std_vector_s.empty());
}

TEST(Vector, function_push_back) {
  s21::vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.push_back(666);
  std_vector.push_back(666);
  s21_vector.push_back(123);
  std_vector.push_back(123);
  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.at(4), std_vector.at(4));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_pop_back) {
  s21::vector<int> s21_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_vector.pop_back();
  std_vector.pop_back();
  s21_vector.pop_back();
  std_vector.pop_back();
  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.at(4), std_vector.at(4));
  ASSERT_EQ(s21_vector.at(5), std_vector.at(5));
  ASSERT_EQ(s21_vector.at(6), std_vector.at(6));
  ASSERT_EQ(s21_vector.at(7), std_vector.at(7));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_reserve) {
  s21::vector<double> s21_vector_empty;
  std::vector<double> std_vector_empty;
  s21_vector_empty.reserve(100);
  std_vector_empty.reserve(100);
  ASSERT_EQ(s21_vector_empty.size(), std_vector_empty.size());
  ASSERT_EQ(s21_vector_empty.capacity(), std_vector_empty.capacity());
  ASSERT_EQ(s21_vector_empty.empty(), std_vector_empty.empty());
  s21::vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.reserve(50);
  std_vector.reserve(50);
  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_shrink_to_fit) {
  s21::vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.reserve(50);
  std_vector.reserve(50);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, function_emplace_begin) {
  s21::vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::vector<int>::const_iterator s21_it = s21_vector.begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.emplace(s21_it, 666);
  std_it = std_vector.emplace(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.at(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.at(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.at(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

// >>>>>>>>>>> ARRAY <<<<<<<<<<<<<<<<
class TestArray {
 public:
  s21::array<int, 0> s21_array_empty;
  s21::array<int, 3> copy_array{234, 21, 11};
  s21::array<char, 0> copy_ar1;
  s21::array<double, 5> copy_array1{2.5, 3.4, 255.3, 1.2, 0.5};
  s21::array<double, 5> copy_array2{-5.3, 1.18, -4.3, 255.34, 1.23};

  std::array<int, 0> std_array_empty;
  std::array<int, 3> orig_array{234, 21, 11};
  std::array<char, 0> orig_ar1;
  std::array<double, 5> orig_array1{2.5, 3.4, 255.3, 1.2, 0.5};
  std::array<double, 5> orig_array2{-5.3, 1.18, -4.3, 255.34, 1.23};
};

TEST(Array, constructor_default) {
  TestArray tester;
  EXPECT_EQ(tester.s21_array_empty.size(), tester.std_array_empty.size());
  EXPECT_EQ(tester.s21_array_empty.empty(), tester.std_array_empty.empty());
}

TEST(Array, constructor_initializer) {
  TestArray tester;
  EXPECT_EQ(tester.copy_array1[1], tester.orig_array1[1]);
  EXPECT_EQ(tester.copy_array1.front(), tester.orig_array1.front());
  EXPECT_EQ(tester.copy_array1.back(), tester.orig_array1.back());
  EXPECT_EQ(tester.copy_array1.size(), tester.orig_array1.size());
  EXPECT_EQ(tester.copy_array1.empty(), tester.orig_array1.empty());
}

TEST(Array, constructor_copy_empty) {
  TestArray tester;
  s21::array<int, 0> s21_array_empty;
  s21::array<int, 0> s21_array_copy(tester.s21_array_empty);
  EXPECT_EQ(s21_array_empty.size(), s21_array_copy.size());
  EXPECT_EQ(s21_array_empty.empty(), s21_array_copy.empty());
}

TEST(Array, simple_test) {
  TestArray logger;
  for (int i{}; i < 3; i++)
    ASSERT_EQ(logger.orig_array.at(i), logger.copy_array.at(i));
  ASSERT_EQ(logger.orig_array.size(), logger.copy_array.size());
  ASSERT_EQ(logger.orig_array.max_size(), logger.copy_array.max_size());
  ASSERT_EQ(logger.orig_ar1.empty(), logger.copy_ar1.empty());
}
TEST(Array, swap_test) {
  TestArray logger;
  logger.orig_array1.swap(logger.orig_array2);
  logger.copy_array1.swap(logger.copy_array2);
  for (int i{}; i < 5; i++) {
    ASSERT_DOUBLE_EQ(logger.orig_array1[i], logger.copy_array1[i]);
    ASSERT_DOUBLE_EQ(logger.orig_array2[i], logger.copy_array2[i]);
  }
  ASSERT_EQ(logger.orig_array1.size(), logger.copy_array1.size());
  ASSERT_EQ(logger.orig_array2.max_size(), logger.copy_array2.max_size());
  ASSERT_EQ(logger.orig_array1.front(), logger.copy_array1.front());
  ASSERT_EQ(logger.orig_array2.front(), logger.copy_array2.front());
  ASSERT_EQ(logger.orig_array1.back(), logger.copy_array1.back());
  ASSERT_EQ(logger.orig_array2.back(), logger.copy_array2.back());
}

TEST(Array, copy_constructor_test) {
  std::array<int, 3> orig_array3{234, 21, 11};
  s21::array<int, 3> copy_array3{234, 21, 11};
  std::array<int, 3> orig_array4(orig_array3);
  s21::array<int, 3> copy_array4(copy_array3);
  for (int i{}; i < 3; i++) {
    ASSERT_EQ(orig_array3.at(i), copy_array3.at(i));
    ASSERT_EQ(orig_array4.at(i), copy_array4.at(i));
  }
  ASSERT_EQ(orig_array3.size(), copy_array3.size());
  ASSERT_EQ(orig_array3.max_size(), copy_array3.max_size());
  ASSERT_EQ(orig_array4.size(), copy_array4.size());
  ASSERT_EQ(orig_array4.max_size(), copy_array4.max_size());
  std::array<char, 0> orig_ar5;
  s21::array<char, 0> copy_ar5;
  std::array<char, 0> orig_ar6(orig_ar5);
  s21::array<char, 0> copy_ar6(copy_ar5);
  ASSERT_EQ(orig_ar5.empty(), copy_ar5.empty());
  ASSERT_EQ(orig_ar6.empty(), copy_ar6.empty());
}

TEST(Array, move_constructor_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::array<int, 5> copy_array1{234, 21, 11, 34, 999};
  std::array<int, 5> orig_array2(std::move(orig_array1));
  s21::array<int, 5> copy_array2(std::move(copy_array1));
  for (size_t i{}; i < copy_array2.size(); i++) {
    ASSERT_EQ(orig_array2.at(i), copy_array2.at(i));
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
  ASSERT_EQ(orig_array2.size(), copy_array2.size());
  ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
  std::array<char, 0> orig_ar1;
  s21::array<char, 0> copy_ar1;
  ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
}

TEST(Array, move_operator_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::array<int, 5> copy_array1{234, 21, 11, 34, 999};
  std::array<int, 5> orig_array2{25};
  s21::array<int, 5> copy_array2{25};
  orig_array2 = std::move(orig_array1);
  copy_array2 = std::move(copy_array1);
  for (size_t i{}; i < copy_array2.size(); i++) {
    ASSERT_EQ(orig_array2.at(i), copy_array2.at(i));
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
  ASSERT_EQ(orig_array2.size(), copy_array2.size());
  ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
  std::array<char, 0> orig_ar1;
  s21::array<char, 0> copy_ar1;
  ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
}

TEST(Array, iterator_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::array<int, 5> copy_array1{234, 21, 11, 34, 999};
  int *orig_beg = orig_array1.begin();
  int *copy_beg = copy_array1.begin();
  int *orig_end = orig_array1.end();
  int *copy_end = copy_array1.end();
  while (orig_beg < orig_end && copy_beg < copy_end) {
    ASSERT_EQ(*orig_beg++, *copy_beg++);
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
  s21::array<char, 0> copy_ar1;
  ASSERT_TRUE(copy_ar1.begin() == copy_ar1.end());
  s21::array<double, 3> my_arr{2.3, 4.5555, 6.1234};
  double *d = my_arr.data();
  ASSERT_DOUBLE_EQ(my_arr[0], *d);
}

TEST(Array, fill_test) {
  std::array<size_t, 10> orig_array;
  s21::array<size_t, 10> my_arr;
  orig_array.fill(555);
  my_arr.fill(555);
  for (size_t i = 0; i < orig_array.size(); i++)
    ASSERT_EQ(orig_array[i], my_arr[i]);
  ASSERT_EQ(orig_array.size(), my_arr.size());
  ;
}
// >>>>>>>>> STACK <<<<<<<<<<<<<<
TEST(Stack, simple_test) {
  s21::stack<int> my_stack;
  std::stack<int> orig_stack;
  my_stack.push(1);
  my_stack.push(2);
  my_stack.push(2555);
  my_stack.push(365434);
  orig_stack.push(1);
  orig_stack.push(2);
  orig_stack.push(2555);
  orig_stack.push(365434);
  while (!orig_stack.empty() && !my_stack.empty()) {
    ASSERT_EQ(orig_stack.top(), my_stack.top());
    orig_stack.pop();
    my_stack.pop();
  }
  ASSERT_EQ(orig_stack.empty(), my_stack.empty());
}
TEST(Stack, swap_test) {
  std::stack<double> orig_stack1;
  orig_stack1.push(2.55);
  orig_stack1.push(3.55);
  orig_stack1.push(222.55);
  orig_stack1.push(984.55);
  orig_stack1.push(123.55);
  orig_stack1.push(0.55);
  orig_stack1.push(-34.55);
  std::stack<double> orig_stack2;
  orig_stack2.push(342.22);
  orig_stack2.push(355.01);
  orig_stack2.push(123.99);
  orig_stack2.push(888.34);
  orig_stack2.push(-23.11);
  orig_stack2.push(1002.88);
  orig_stack2.push(1.55);
  s21::stack<double> my_stack1;
  my_stack1.push(2.55);
  my_stack1.push(3.55);
  my_stack1.push(222.55);
  my_stack1.push(984.55);
  my_stack1.push(123.55);
  my_stack1.push(0.55);
  my_stack1.push(-34.55);
  s21::stack<double> my_stack2;
  my_stack2.push(342.22);
  my_stack2.push(355.01);
  my_stack2.push(123.99);
  my_stack2.push(888.34);
  my_stack2.push(-23.11);
  my_stack2.push(1002.88);
  my_stack2.push(1.55);
  orig_stack1.swap(orig_stack2);
  my_stack1.swap(my_stack2);
  while (!orig_stack1.empty() && !my_stack1.empty()) {
    ASSERT_DOUBLE_EQ(orig_stack1.top(), my_stack1.top());
    orig_stack1.pop();
    my_stack1.pop();
  }
  while (!orig_stack2.empty() && !my_stack2.empty()) {
    ASSERT_DOUBLE_EQ(orig_stack2.top(), my_stack2.top());
    orig_stack2.pop();
    my_stack2.pop();
  }
  ASSERT_EQ(orig_stack2.empty(), my_stack2.empty());
}

TEST(Stack, copy_constructor_test) {
  std::stack<int> orig_stack1;
  orig_stack1.push(55);
  orig_stack1.push(555);
  orig_stack1.push(5555);
  orig_stack1.push(55555);
  std::stack<int> orig_stack2(orig_stack1);
  s21::stack<int> my_stack1;
  my_stack1.push(55);
  my_stack1.push(555);
  my_stack1.push(5555);
  my_stack1.push(55555);
  s21::stack<int> my_stack2(my_stack1);
  while (!orig_stack2.empty() && !my_stack2.empty()) {
    ASSERT_EQ(orig_stack2.top(), my_stack2.top());
    orig_stack2.pop();
    my_stack2.pop();
  }
  s21::stack<int> my_stack3;
  std::stack<int> orig_stack3;
  s21::stack<int> my_stack4(my_stack3);
  std::stack<int> orig_stack4(orig_stack3);
  ASSERT_EQ(orig_stack4.empty(), my_stack4.empty());
}

TEST(Stack, move_constructor_test) {
  std::stack<int> orig_stack1;
  orig_stack1.push(55);
  orig_stack1.push(555);
  orig_stack1.push(5555);
  orig_stack1.push(55555);
  std::stack<int> orig_stack2(std::move(orig_stack1));
  s21::stack<int> copy_stack1;
  copy_stack1.push(55);
  copy_stack1.push(555);
  copy_stack1.push(5555);
  copy_stack1.push(55555);
  s21::stack<int> copy_stack2(std::move(copy_stack1));
  while (!orig_stack2.empty() && !copy_stack2.empty()) {
    ASSERT_EQ(orig_stack2.top(), copy_stack2.top());
    orig_stack2.pop();
    copy_stack2.pop();
  }
  ASSERT_EQ(orig_stack1.size(), copy_stack1.size());
}

TEST(Stack, move_operator_test) {
  std::stack<int> orig_stack1;
  orig_stack1.push(55);
  orig_stack1.push(555);
  orig_stack1.push(5555);
  orig_stack1.push(55555);
  std::stack<int> orig_stack2;
  orig_stack2.push(1);
  orig_stack2.push(2);
  orig_stack2 = std::move(orig_stack1);
  s21::stack<int> copy_stack1;
  copy_stack1.push(55);
  copy_stack1.push(555);
  copy_stack1.push(5555);
  copy_stack1.push(55555);
  s21::stack<int> copy_stack2{1, 2};
  copy_stack2 = std::move(copy_stack1);
  while (!orig_stack2.empty() && !copy_stack2.empty()) {
    ASSERT_EQ(orig_stack2.top(), copy_stack2.top());
    orig_stack2.pop();
    copy_stack2.pop();
  }
  ASSERT_EQ(orig_stack1.size(), copy_stack1.size());
}

TEST(Stack, emplace_test) {
  std::stack<int> orig_stack1;
  orig_stack1.push(55);
  orig_stack1.push(555);
  orig_stack1.push(5555);
  orig_stack1.push(55555);
  orig_stack1.emplace(345);
  orig_stack1.emplace(234);
  orig_stack1.emplace(889);
  s21::stack<int> copy_stack1;
  copy_stack1.push(55);
  copy_stack1.push(555);
  copy_stack1.push(5555);
  copy_stack1.push(55555);
  copy_stack1.emplace_front(345);
  copy_stack1.emplace_front(234);
  copy_stack1.emplace_front(889);
  while (!orig_stack1.empty() && !copy_stack1.empty()) {
    ASSERT_EQ(orig_stack1.top(), copy_stack1.top());
    orig_stack1.pop();
    copy_stack1.pop();
  }
  ASSERT_EQ(orig_stack1.size(), copy_stack1.size());
}

// List Testing
class TestList {
 public:
  s21::list<int> s21_list_empty;
  s21::list<int> s21_list_three{1, 2, 3};
  s21::list<int> s21_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  s21::list<char> s21_char_list{'L', 'I', 'S', 'T'};
  s21::list<int> s21_list_ten{1, 2, 3, 5, 9, 10};
  s21::list<int> s21_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};

  std::list<int> std_list_empty;
  std::list<int> std_list_three{1, 2, 3};
  std::list<int> std_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  std::list<char> std_char_list{'L', 'I', 'S', 'T'};
  std::list<int> std_list_ten{1, 2, 3, 5, 9, 10};
  std::list<int> std_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};
};

TEST(List, default_constructor) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.size(), tester.std_list_empty.size());
  EXPECT_EQ(tester.s21_list_empty.empty(), tester.std_list_empty.empty());
}

TEST(List, init_constructor) {
  TestList tester;
  s21::list<int> a(3);
  std::list<int> b(3);
  s21::list<int>::iterator s21_it = a.begin();
  std::list<int>::iterator std_it = b.begin();
  while (s21_it != a.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(List, initializer_constructor) {
  TestList tester;
  s21::list<int>::iterator s21_iter = tester.s21_list_three.begin();
  std::list<int>::iterator std_iter = tester.std_list_three.begin();
  while (s21_iter != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, copy_constructor) {
  TestList tester;
  s21::list<int> s21_list_copy(tester.s21_list_three);
  std::list<int> std_list_copy(tester.std_list_three);
  s21::list<int>::iterator s21_iter = s21_list_copy.begin();
  std::list<int>::iterator std_iter = std_list_copy.begin();
  while (s21_iter != s21_list_copy.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
  EXPECT_EQ(s21_list_copy.empty(), std_list_copy.empty());
}

TEST(List, move_constructor) {
  TestList tester;
  s21::list<int> s21_list_move(std::move(tester.s21_list_three));
  std::list<int> std_list_move(std::move(tester.std_list_three));
  s21::list<int>::iterator s21_iter = s21_list_move.begin();
  std::list<int>::iterator std_iter = std_list_move.begin();
  while (s21_iter != s21_list_move.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_move.size(), std_list_move.size());
  EXPECT_EQ(s21_list_move.empty(), std_list_move.empty());
  s21_iter = tester.s21_list_three.begin();
  std_iter = tester.std_list_three.begin();
  while (s21_iter != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, copy_assigment_lesser) {
  TestList tester;
  s21::list<int> s21_list_copy{1, 2};
  std::list<int> std_list_copy{1, 2};
  s21_list_copy = tester.s21_lesser;
  std_list_copy = tester.std_lesser;
  s21::list<int>::iterator s21_iter = s21_list_copy.begin();
  std::list<int>::iterator std_iter = std_list_copy.begin();
  while (s21_iter != s21_list_copy.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
  EXPECT_EQ(s21_list_copy.empty(), std_list_copy.empty());
}

TEST(List, move_assigment) {
  TestList tester;
  s21::list<int> s21_list_move{1, 2};
  std::list<int> std_list_move{1, 2};
  s21_list_move = std::move(tester.s21_lesser);
  std_list_move = std::move(tester.std_lesser);
  s21::list<int>::iterator s21_iter = s21_list_move.begin();
  std::list<int>::iterator std_iter = std_list_move.begin();
  while (s21_iter != s21_list_move.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_move.size(), std_list_move.size());
  EXPECT_EQ(s21_list_move.empty(), std_list_move.empty());
}

TEST(List, function_front) {
  TestList tester;
  EXPECT_EQ(tester.s21_char_list.front(), tester.std_char_list.front());
}
TEST(List, function_front_empty) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.front(), tester.std_list_empty.front());
}

TEST(List, function_back) {
  TestList tester;
  EXPECT_EQ(tester.s21_char_list.back(), tester.std_char_list.back());
}
TEST(List, function_back_empty) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.back(), tester.std_list_empty.back());
}

TEST(List, iterator_access_first) {
  TestList tester;
  s21::list<char>::iterator s21_iter = tester.s21_char_list.begin();
  std::list<char>::iterator std_iter = tester.std_char_list.begin();
  while (s21_iter != tester.s21_char_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
}

TEST(List, function_empty) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.empty(), tester.std_list_empty.empty());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, function_size) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_empty.size(), tester.std_list_empty.size());
}

TEST(List, function_max_size) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.max_size(), tester.std_list_empty.max_size());
}

TEST(List, function_clear) {
  TestList tester;
  tester.s21_list_three.clear();
  tester.std_list_three.clear();
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
}

TEST(List, function_insert_begin) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_empty.begin();
  std::list<int>::iterator std_it = tester.std_list_empty.begin();
  s21_it = tester.s21_list_empty.insert(s21_it, 666);
  std_it = tester.std_list_empty.insert(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_empty.begin();
  std_it = tester.std_list_empty.begin();
  while (s21_it != tester.s21_list_empty.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_empty.size(), tester.std_list_empty.size());
  EXPECT_EQ(tester.s21_list_empty.empty(), tester.std_list_empty.empty());
}

TEST(List, function_insert_mid) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_insert_end) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.end();
  std::list<int>::iterator std_it = tester.std_list_ten.end();
  s21_it = tester.s21_list_ten.insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_insert_multi) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  s21_it = tester.s21_list_ten.insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_begin) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_mid) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_end) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.rbegin();
  std::list<int>::iterator std_it = --tester.std_list_ten.end();
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_multi) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}
TEST(List, function_push_back) {
  TestList tester;
  tester.s21_list_three.push_back(666);
  tester.std_list_three.push_back(666);
  tester.s21_list_three.push_back(123);
  tester.std_list_three.push_back(123);
  s21::list<int>::iterator s21_it = tester.s21_list_three.begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, function_pop_back) {
  TestList tester;
  tester.s21_list_ten.pop_back();
  tester.std_list_ten.pop_back();
  tester.s21_list_ten.pop_back();
  tester.std_list_ten.pop_back();
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_push_front) {
  TestList tester;
  tester.s21_list_ten.push_front(666);
  tester.std_list_ten.push_front(666);
  tester.s21_list_ten.push_front(123);
  tester.std_list_ten.push_front(123);
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_pop_front) {
  TestList tester;
  tester.s21_list_ten.pop_front();
  tester.std_list_ten.pop_front();
  tester.s21_list_ten.pop_front();
  tester.std_list_ten.pop_front();
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_swap) {
  TestList tester;
  s21::list<int> s21_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> std_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  tester.s21_lesser.swap(s21_list_swap);
  tester.std_lesser.swap(std_list_swap);
  s21::list<int>::iterator s21_it = s21_list_swap.begin();
  std::list<int>::iterator std_it = std_list_swap.begin();
  while (s21_it != s21_list_swap.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_swap.size(), std_list_swap.size());
  EXPECT_EQ(s21_list_swap.empty(), std_list_swap.empty());
  s21_it = tester.s21_lesser.begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}
TEST(List, function_merge_nonsorted) {
  TestList tester;
  s21::list<int> s21_list_merge{77, 125890, 430235, -236, 32858, 7457};
  std::list<int> std_list_merge{77, 125890, 430235, -236, 32858, 7457};
  tester.s21_lesser.merge(s21_list_merge);
  tester.std_lesser.merge(std_list_merge);
  s21::list<int>::iterator s21_it = s21_list_merge.begin();
  std::list<int>::iterator std_it = std_list_merge.begin();
  while (s21_it != s21_list_merge.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_merge.size(), std_list_merge.size());
  EXPECT_EQ(s21_list_merge.empty(), std_list_merge.empty());
  s21_it = tester.s21_lesser.begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

TEST(List, function_merge_sorted) {
  TestList tester;
  s21::list<int> s21_list_merge{77, 125890, 430235, -236, 32858, 7457};
  std::list<int> std_list_merge{77, 125890, 430235, -236, 32858, 7457};
  tester.s21_lesser.sort();
  tester.std_lesser.sort();
  tester.s21_lesser.merge(s21_list_merge);
  tester.std_lesser.merge(std_list_merge);
  s21::list<int>::iterator s21_it = s21_list_merge.begin();
  std::list<int>::iterator std_it = std_list_merge.begin();
  while (s21_it != s21_list_merge.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_merge.size(), std_list_merge.size());
  EXPECT_EQ(s21_list_merge.empty(), std_list_merge.empty());
  s21_it = tester.s21_lesser.begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

TEST(List, function_splice) {
  TestList tester;
  s21::list<int> s21_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> std_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::list<int>::const_iterator s21_it = tester.s21_lesser.cbegin();
  std::list<int>::const_iterator std_it = tester.std_lesser.cbegin();
  ++s21_it;
  ++std_it;
  tester.s21_lesser.splice(s21_it, s21_list_splice);
  tester.std_lesser.splice(std_it, std_list_splice);
  s21_it = s21_list_splice.cbegin();
  std_it = std_list_splice.cbegin();
  while (s21_it != s21_list_splice.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_splice.size(), std_list_splice.size());
  EXPECT_EQ(s21_list_splice.empty(), std_list_splice.empty());
  s21_it = tester.s21_lesser.cbegin();
  std_it = tester.std_lesser.cbegin();
  while (s21_it != tester.s21_lesser.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

TEST(List, function_reverse) {
  TestList tester;
  tester.s21_list_ten.reverse();
  tester.std_list_ten.reverse();
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_unique) {
  TestList tester;
  tester.s21_list_unique.unique();
  tester.std_list_unique.unique();
  s21::list<int>::iterator s21_it = tester.s21_list_unique.begin();
  std::list<int>::iterator std_it = tester.std_list_unique.begin();
  while (s21_it != tester.s21_list_unique.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_unique.size(), tester.std_list_unique.size());
  EXPECT_EQ(tester.s21_list_unique.empty(), tester.std_list_unique.empty());
}

TEST(List, function_sort) {
  TestList tester;
  tester.s21_lesser.sort();
  tester.std_lesser.sort();
  s21::list<int>::iterator s21_it = tester.s21_lesser.begin();
  std::list<int>::iterator std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

TEST(List, function_emplace_begin) {
  TestList tester;
  s21::list<int>::const_iterator s21_it = tester.s21_list_ten.cbegin();
  std::list<int>::const_iterator std_it = tester.std_list_ten.cbegin();
  auto s21_iter = tester.s21_list_ten.emplace(s21_it, 666);
  auto std_iter = tester.std_list_ten.emplace(std_it, 666);
  ASSERT_EQ(*s21_iter, *std_iter);
  s21_it = tester.s21_list_ten.cbegin();
  std_it = tester.std_list_ten.cbegin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_mid) {
  TestList tester;
  s21::list<int>::const_iterator s21_it = tester.s21_list_ten.cbegin();
  std::list<int>::const_iterator std_it = tester.std_list_ten.cbegin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  auto s21_iter = tester.s21_list_ten.emplace(s21_it, 666);
  auto std_iter = tester.std_list_ten.emplace(std_it, 666);
  ASSERT_EQ(*s21_iter, *std_iter);
  s21_it = tester.s21_list_ten.cbegin();
  std_it = tester.std_list_ten.cbegin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_end) {
  TestList tester;
  s21::list<int>::const_iterator s21_it = tester.s21_list_ten.cend();
  std::list<int>::const_iterator std_it = tester.std_list_ten.cend();
  auto s21_iter = tester.s21_list_ten.emplace(s21_it, 666);
  auto std_iter = tester.std_list_ten.emplace(std_it, 666);
  EXPECT_EQ(*s21_iter, *std_iter);
  while (s21_it != tester.s21_list_ten.cend()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_multi) {
  TestList tester;
  s21::list<int>::const_iterator s21_it = tester.s21_list_ten.cbegin();
  std::list<int>::const_iterator std_it = tester.std_list_ten.cbegin();
  s21::list<int>::iterator s21_iter = tester.s21_list_ten.emplace(s21_it, 666);
  std::list<int>::iterator std_iter = tester.std_list_ten.emplace(std_it, 666);

  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_iter = tester.s21_list_ten.emplace(s21_it, 666);
  std_iter = tester.std_list_ten.emplace(std_it, 666);

  ASSERT_EQ(*s21_it, *std_it);

  auto s21_iterator = tester.s21_list_ten.begin();
  auto std_iterator = tester.std_list_ten.begin();

  while (s21_iterator != tester.s21_list_ten.end()) {
    ASSERT_EQ(*s21_iterator, *std_iterator);
    ++s21_iterator;
    ++std_iterator;
  }

  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_back) {
  TestList tester;
  tester.s21_list_three.emplace_back(666);
  tester.std_list_three.emplace_back(666);
  tester.s21_list_three.emplace_back(123);
  tester.std_list_three.emplace_back(123);
  s21::list<int>::iterator s21_it = tester.s21_list_three.begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, function_emplace_front) {
  TestList tester;
  tester.s21_list_three.emplace_front(666);
  tester.std_list_three.emplace_front(666);
  tester.s21_list_three.emplace_front(123);
  tester.std_list_three.emplace_front(123);
  s21::list<int>::iterator s21_it = tester.s21_list_three.begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

// Queue Test
class TestQueue {
 public:
  s21::queue<int> s21_queue_empty;
  s21::queue<int> s21_queue_three;

  std::queue<int> std_queue_empty;
  std::queue<int> std_queue_three;
};

TEST(Queue, default_constructor) {
  TestQueue tester;
  EXPECT_EQ(tester.s21_queue_empty.size(), tester.std_queue_empty.size());
  EXPECT_EQ(tester.s21_queue_empty.empty(), tester.std_queue_empty.empty());
}

TEST(Queue, initializer_constructor) {
  TestQueue tester;
  while (!tester.s21_queue_three.empty()) {
    EXPECT_EQ(tester.s21_queue_three.front(), tester.std_queue_three.front());
    tester.s21_queue_three.pop();
    tester.std_queue_three.pop();
  }
  EXPECT_EQ(tester.s21_queue_three.size(), tester.std_queue_three.size());
  EXPECT_EQ(tester.s21_queue_three.empty(), tester.std_queue_three.empty());
}

TEST(Queue, move_constructor) {
  TestQueue tester;
  s21::queue<int> s21_queue_move(std::move(tester.s21_queue_three));
  std::queue<int> std_queue_move(std::move(tester.std_queue_three));
  while (!s21_queue_move.empty()) {
    EXPECT_EQ(s21_queue_move.front(), std_queue_move.front());
    s21_queue_move.pop();
    std_queue_move.pop();
  }
  EXPECT_EQ(s21_queue_move.size(), std_queue_move.size());
  EXPECT_EQ(s21_queue_move.empty(), std_queue_move.empty());
  while (!tester.s21_queue_three.empty()) {
    EXPECT_EQ(tester.s21_queue_three.front(), tester.s21_queue_three.front());
    tester.s21_queue_three.pop();
    tester.std_queue_three.pop();
  }
  EXPECT_EQ(tester.s21_queue_three.size(), tester.std_queue_three.size());
  EXPECT_EQ(tester.s21_queue_three.empty(), tester.std_queue_three.empty());
}

TEST(Queue, move_assigment) {
  TestQueue tester;
  s21::queue<int> s21_queue_move{1, 2};
  std::queue<int> std_queue_move;
  std_queue_move.push(1);
  std_queue_move.push(2);
  s21_queue_move = std::move(tester.s21_queue_three);
  std_queue_move = std::move(tester.std_queue_three);
  while (!s21_queue_move.empty()) {
    EXPECT_EQ(s21_queue_move.front(), std_queue_move.front());
    s21_queue_move.pop();
    std_queue_move.pop();
  }
  EXPECT_EQ(s21_queue_move.size(), std_queue_move.size());
  EXPECT_EQ(s21_queue_move.empty(), std_queue_move.empty());
}

TEST(Queue, function_push) {
  TestQueue tester;
  for (int i = 0; i < 10; i++) {
    tester.s21_queue_empty.push(i);
    tester.std_queue_empty.push(i);
  }
  while (!tester.std_queue_empty.empty() && !tester.s21_queue_empty.empty()) {
    EXPECT_EQ(tester.std_queue_empty.front(), tester.s21_queue_empty.front());
    EXPECT_EQ(tester.std_queue_empty.back(), tester.s21_queue_empty.back());
    tester.std_queue_empty.pop();
    tester.s21_queue_empty.pop();
  }
  EXPECT_EQ(tester.std_queue_empty.empty(), tester.s21_queue_empty.empty());
}

TEST(Queue, function_pop) {
  TestQueue tester;
  for (int i = 0; i < 456; i++) {
    tester.s21_queue_empty.push(i);
    tester.std_queue_empty.push(i);
  }
  while (!tester.std_queue_empty.empty() && !tester.s21_queue_empty.empty()) {
    EXPECT_EQ(tester.std_queue_empty.front(), tester.s21_queue_empty.front());
    EXPECT_EQ(tester.std_queue_empty.back(), tester.s21_queue_empty.back());
    tester.std_queue_empty.pop();
    tester.s21_queue_empty.pop();
  }
  EXPECT_EQ(tester.std_queue_empty.empty(), tester.s21_queue_empty.empty());
}

TEST(Queue, simple_test) {
  TestQueue tester;
  tester.s21_queue_empty.push(1);
  tester.s21_queue_empty.push(2);
  tester.s21_queue_empty.push(2555);
  tester.s21_queue_empty.push(365434);
  tester.std_queue_empty.push(1);
  tester.std_queue_empty.push(2);
  tester.std_queue_empty.push(2555);
  tester.std_queue_empty.push(365434);
  while (!tester.std_queue_empty.empty() && !tester.s21_queue_empty.empty()) {
    EXPECT_EQ(tester.std_queue_empty.front(), tester.s21_queue_empty.front());
    EXPECT_EQ(tester.std_queue_empty.back(), tester.s21_queue_empty.back());
    tester.std_queue_empty.pop();
    tester.s21_queue_empty.pop();
  }
  EXPECT_EQ(tester.std_queue_empty.empty(), tester.s21_queue_empty.empty());
}

TEST(Queue, swap_test) {
  std::queue<double> orig_queue1;
  orig_queue1.push(2.55);
  orig_queue1.push(3.55);
  orig_queue1.push(222.55);
  orig_queue1.push(984.55);
  orig_queue1.push(123.55);
  orig_queue1.push(0.55);
  orig_queue1.push(-34.55);
  std::queue<double> orig_queue2;
  orig_queue2.push(342.22);
  orig_queue2.push(355.01);
  orig_queue2.push(123.99);
  orig_queue2.push(888.34);
  orig_queue2.push(-23.11);
  orig_queue2.push(1002.88);
  orig_queue2.push(1.55);
  s21::queue<double> my_queue1;
  my_queue1.push(2.55);
  my_queue1.push(3.55);
  my_queue1.push(222.55);
  my_queue1.push(984.55);
  my_queue1.push(123.55);
  my_queue1.push(0.55);
  my_queue1.push(-34.55);
  s21::queue<double> my_queue2;
  my_queue2.push(342.22);
  my_queue2.push(355.01);
  my_queue2.push(123.99);
  my_queue2.push(888.34);
  my_queue2.push(-23.11);
  my_queue2.push(1002.88);
  my_queue2.push(1.55);
  orig_queue1.swap(orig_queue2);
  my_queue1.swap(my_queue2);
  while (!orig_queue1.empty() && !my_queue1.empty()) {
    ASSERT_DOUBLE_EQ(orig_queue1.front(), my_queue1.front());
    ASSERT_DOUBLE_EQ(orig_queue1.back(), my_queue1.back());
    orig_queue1.pop();
    my_queue1.pop();
  }
  while (!orig_queue2.empty() && !my_queue2.empty()) {
    ASSERT_DOUBLE_EQ(orig_queue2.front(), my_queue2.front());
    ASSERT_DOUBLE_EQ(orig_queue2.back(), my_queue2.back());
    orig_queue2.pop();
    my_queue2.pop();
  }
  ASSERT_EQ(orig_queue2.empty(), my_queue2.empty());
}

TEST(Queue, copy_constructor_test) {
  s21::queue<int> my_queue;
  std::queue<int> orig_queue;
  s21::queue<int> my_queue2(my_queue);
  std::queue<int> orig_queue2(orig_queue);
  ASSERT_EQ(orig_queue2.empty(), my_queue2.empty());

  std::queue<char> orig_q1;
  orig_q1.push('a');
  orig_q1.push('b');
  orig_q1.push('c');
  orig_q1.push('d');
  s21::queue<char> copy_q1;
  copy_q1.push('a');
  copy_q1.push('b');
  copy_q1.push('c');
  copy_q1.push('d');
  std::queue<char> orig_q2(orig_q1);
  s21::queue<char> copy_q2(copy_q1);
  ASSERT_EQ(orig_q2.size(), copy_q2.size());
  while (!orig_q2.empty() && !copy_q2.empty()) {
    ASSERT_EQ(orig_q2.front(), copy_q2.front());
    ASSERT_EQ(orig_q2.back(), copy_q2.back());
    orig_q2.pop();
    copy_q2.pop();
  }
}

TEST(Queue, move_constructor_test) {
  std::queue<char> orig_q1;
  orig_q1.push('a');
  orig_q1.push('b');
  orig_q1.push('c');
  orig_q1.push('d');
  s21::queue<char> copy_q1;
  copy_q1.push('a');
  copy_q1.push('b');
  copy_q1.push('c');
  copy_q1.push('d');
  std::queue<char> orig_q2(std::move(orig_q1));
  s21::queue<char> copy_q2(std::move(copy_q1));
  ASSERT_EQ(orig_q1.size(), copy_q1.size());
  ASSERT_EQ(orig_q2.size(), copy_q2.size());
  while (!orig_q2.empty() && !copy_q2.empty()) {
    ASSERT_EQ(orig_q2.front(), copy_q2.front());
    ASSERT_EQ(orig_q2.back(), copy_q2.back());
    orig_q2.pop();
    copy_q2.pop();
  }
}

TEST(Queue, move_operator_test) {
  std::queue<char> orig_q1;
  orig_q1.push('a');
  orig_q1.push('b');
  orig_q1.push('c');
  orig_q1.push('d');
  s21::queue<char> copy_q1;
  copy_q1.push('a');
  copy_q1.push('b');
  copy_q1.push('c');
  copy_q1.push('d');
  std::queue<char> orig_q2;
  orig_q2.push('h');
  s21::queue<char> copy_q2{'h'};
  EXPECT_EQ(orig_q1.size(), copy_q1.size());
  EXPECT_EQ(orig_q2.size(), copy_q2.size());
  orig_q2 = std::move(orig_q1);
  copy_q2 = std::move(copy_q1);
  EXPECT_EQ(orig_q1.size(), copy_q1.size());
  EXPECT_EQ(orig_q2.size(), copy_q2.size());
  while (!orig_q2.empty() && !copy_q2.empty()) {
    EXPECT_EQ(orig_q2.front(), copy_q2.front());
    EXPECT_EQ(orig_q2.back(), copy_q2.back());
    orig_q2.pop();
    copy_q2.pop();
  }
}

TEST(Queue, emplace_test) {
  std::queue<char> orig_q1;
  orig_q1.push('a');
  orig_q1.push('b');
  orig_q1.push('c');
  orig_q1.push('d');
  orig_q1.emplace('p');
  orig_q1.emplace('z');
  orig_q1.emplace('i');
  s21::queue<char> copy_q1;
  copy_q1.push('a');
  copy_q1.push('b');
  copy_q1.push('c');
  copy_q1.push('d');
  copy_q1.emplace_back('p');
  copy_q1.emplace_back('z');
  copy_q1.emplace_back('i');
  while (!orig_q1.empty() && !copy_q1.empty()) {
    EXPECT_EQ(orig_q1.front(), copy_q1.front());
    EXPECT_EQ(orig_q1.back(), copy_q1.back());
    orig_q1.pop();
    copy_q1.pop();
  }
  EXPECT_EQ(orig_q1.size(), copy_q1.size());
}
// SET
class TestSet {
 public:
  s21::set<int> s21_set_empty;
  s21::set<int> s21_set_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
  s21::set<int> s21_set_copy;
  std::set<int> std_set_copy;
  s21::set<int> s21_move;
  std::set<int> std_move;
  s21::set<int> s21_set_swap{95, 94, 93, 92};
  std::set<int> std_set_swap{95, 94, 93, 92};
  s21::set<int> s21_set_merge{1, 2, 3, 4, 5};
  std::set<int> std_set_merge{1, 2, 3, 4, 5};

  std::set<int> std_set_empty;
  std::set<int> std_set_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
};

TEST(Set, constructor_default) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, constructor_initialazer) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.find(1) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(1) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(2) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(2) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(3) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(3) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(4) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(4) != tester.std_set_ten.end());
}

TEST(Set, constructor_copy) {
  TestSet tester;
  s21::set<int> s21_empty(tester.s21_set_ten);
  std::set<int> std_empty(tester.std_set_ten);
  EXPECT_EQ(s21_empty.find(1) != s21_empty.end(),
            std_empty.find(1) != std_empty.end());
  EXPECT_EQ(s21_empty.find(2) != s21_empty.end(),
            std_empty.find(2) != std_empty.end());
  EXPECT_EQ(s21_empty.find(3) != s21_empty.end(),
            std_empty.find(3) != std_empty.end());
  EXPECT_EQ(s21_empty.find(4) != s21_empty.end(),
            std_empty.find(4) != std_empty.end());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  EXPECT_EQ(s21_empty.empty(), std_empty.empty());
}

TEST(Set, construct_move) {
  TestSet tester;
  s21::set<int> s21_move = std::move(tester.s21_set_ten);
  std::set<int> std_move = std::move(tester.std_set_ten);
  EXPECT_EQ(s21_move.find(1) != s21_move.end(),
            std_move.find(1) != std_move.end());
  EXPECT_EQ(s21_move.find(2) != s21_move.end(),
            std_move.find(2) != std_move.end());
  EXPECT_EQ(s21_move.find(3) != s21_move.end(),
            std_move.find(3) != std_move.end());
  EXPECT_EQ(s21_move.find(4) != s21_move.end(),
            std_move.find(4) != std_move.end());
  EXPECT_EQ(s21_move.size(), std_move.size());
  EXPECT_EQ(s21_move.empty(), std_move.empty());
}

TEST(Set, operator_move) {
  TestSet tester;
  tester.s21_move = std::move(tester.s21_set_ten);
  tester.std_move = std::move(tester.std_set_ten);
  EXPECT_EQ(tester.s21_move.find(1) != tester.s21_move.end(),
            tester.std_move.find(1) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(2) != tester.s21_move.end(),
            tester.std_move.find(2) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(3) != tester.s21_move.end(),
            tester.std_move.find(3) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(4) != tester.s21_move.end(),
            tester.std_move.find(4) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.size(), tester.std_move.size());
  EXPECT_EQ(tester.s21_move.empty(), tester.std_move.empty());
}

TEST(Set, operator_copy) {
  TestSet tester;
  tester.s21_set_copy = tester.s21_set_ten;
  tester.std_set_copy = tester.std_set_ten;
  EXPECT_EQ(tester.s21_set_copy.find(1) != tester.s21_set_copy.end(),
            tester.std_set_copy.find(1) != tester.std_set_copy.end());
  EXPECT_EQ(tester.s21_set_copy.find(2) != tester.s21_set_copy.end(),
            tester.std_set_copy.find(2) != tester.std_set_copy.end());
  EXPECT_EQ(tester.s21_set_copy.find(3) != tester.s21_set_copy.end(),
            tester.std_set_copy.find(3) != tester.std_set_copy.end());
  EXPECT_EQ(tester.s21_set_copy.find(4) != tester.s21_set_copy.end(),
            tester.std_set_copy.find(4) != tester.std_set_copy.end());
  EXPECT_EQ(tester.s21_set_copy.size(), tester.std_set_copy.size());
  EXPECT_EQ(tester.s21_set_copy.empty(), tester.std_set_copy.empty());
}

TEST(Set, function_not_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, function_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, function_size_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
}

TEST(Set, function_size_not_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Set, function_max_sez_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.max_size(), tester.std_set_empty.max_size());
}

TEST(Set, function_max_siez_not_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.max_size(), tester.std_set_ten.max_size());
}

TEST(Set, function_max_size_float_empty) {
  s21::set<float> s21_float_empty;
  std::set<float> std_float_empty;
  EXPECT_EQ(s21_float_empty.max_size(), std_float_empty.max_size());
}

TEST(Set, function_swap_not_empty) {
  TestSet tester;
  tester.s21_set_swap.swap(tester.s21_set_ten);
  tester.std_set_swap.swap(tester.std_set_ten);
  EXPECT_EQ(tester.s21_set_swap.find(1) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(1) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.find(56) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(56) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.find(76) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(76) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_ten.find(95) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(95) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(94) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(94) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(93) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(93) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Set, function_swap_empty) {
  TestSet tester;
  tester.s21_set_empty.swap(tester.s21_set_swap);
  tester.std_set_empty.swap(tester.std_set_swap);

  EXPECT_EQ(tester.s21_set_empty.find(95) != tester.s21_set_empty.end(),
            tester.std_set_empty.find(95) != tester.std_set_empty.end());
  EXPECT_EQ(tester.s21_set_empty.find(94) != tester.s21_set_empty.end(),
            tester.std_set_empty.find(94) != tester.std_set_empty.end());
  EXPECT_EQ(tester.s21_set_empty.find(93) != tester.s21_set_empty.end(),
            tester.std_set_empty.find(93) != tester.std_set_empty.end());

  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_swap.empty(), tester.std_set_swap.empty());
}
TEST(Set, function_merge_with_duplicates) {
  TestSet tester;
  tester.s21_set_merge.merge(tester.s21_set_ten);
  tester.std_set_merge.merge(tester.std_set_ten);

  EXPECT_EQ(tester.s21_set_merge.find(1) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(1) != tester.std_set_merge.end());
  EXPECT_EQ(tester.s21_set_merge.find(2) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(2) != tester.std_set_merge.end());
  EXPECT_EQ(tester.s21_set_merge.find(76) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(76) != tester.std_set_merge.end());

  EXPECT_EQ(tester.s21_set_merge.size(), tester.std_set_merge.size());
  EXPECT_EQ(tester.std_set_merge.empty(), tester.std_set_merge.empty());
}

TEST(Set, function_merge_wihout_duplicates) {
  TestSet tester;
  tester.s21_set_ten.merge(tester.s21_set_swap);
  tester.std_set_ten.merge(tester.std_set_swap);

  EXPECT_EQ(tester.s21_set_ten.find(95) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(95) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(1) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(1) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(94) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(94) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(76) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(76) != tester.std_set_ten.end());

  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.std_set_ten.empty(), tester.std_set_ten.empty());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_swap.empty(), tester.std_set_swap.empty());
}

TEST(Set, function_clear_not_empty) {
  TestSet tester;
  tester.s21_set_ten.clear();
  tester.std_set_ten.clear();
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, function_clear_empty) {
  TestSet tester;
  tester.s21_set_empty.clear();
  tester.std_set_empty.clear();
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.std_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, function_begin_not_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.begin();
  std::set<int>::iterator j = tester.std_set_ten.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_begin_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_empty.begin();
  std::set<int>::iterator j = tester.std_set_empty.begin();
  EXPECT_EQ(*i, *j);
}
TEST(Set, function_const_begin_not_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.begin();
  std::set<int>::iterator j = tester.std_set_ten.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_const_begin_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_empty.begin();
  std::set<int>::iterator j = tester.std_set_empty.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_end_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_empty.end();
  std::set<int>::iterator j = tester.std_set_empty.end();
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_const_end_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_empty.end();
  std::set<int>::iterator j = tester.std_set_empty.end();
  EXPECT_EQ(*i, *j);
}

TEST(Set, operator_plus) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.begin();
  std::set<int>::iterator j = tester.std_set_ten.begin();
  while (i != tester.s21_set_ten.end() && j != tester.std_set_ten.end()) {
    EXPECT_EQ(*i, *j);
    ++i;
    ++j;
  }
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.std_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, operator_minus) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.rbegin();
  std::set<int>::iterator j = --tester.std_set_ten.end();
  while (i != tester.s21_set_ten.begin() && j != tester.std_set_ten.begin()) {
    --i;
    --j;
    EXPECT_EQ(*i, *j);
  }
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, operation_assignment) {
  TestSet tester;
  s21::set<int>::iterator iter_1 = tester.s21_set_ten.begin();
  s21::set<int>::iterator iter_3 = iter_1;
  std::set<int>::iterator iter_2 = tester.std_set_ten.begin();
  std::set<int>::iterator iter_4 = iter_2;
  ASSERT_EQ(*iter_1, *iter_3);
  ASSERT_EQ(*iter_2, *iter_4);
}
TEST(Set, operation_equal) {
  TestSet tester;
  s21::set<int>::iterator it1 = tester.s21_set_ten.begin();
  s21::set<int>::iterator it3 = tester.s21_set_ten.begin();
  std::set<int>::iterator it2 = tester.std_set_ten.begin();
  std::set<int>::iterator it4 = tester.std_set_ten.begin();
  ASSERT_EQ(it1 == it3, it2 == it4);
}
TEST(Set, operation_not_equal) {
  TestSet tester;
  s21::set<int>::iterator iter_1 = tester.s21_set_ten.begin();
  std::set<int>::iterator iter_2 = tester.std_set_ten.begin();
  ASSERT_EQ(iter_1 != tester.s21_set_ten.end(),
            iter_2 != tester.std_set_ten.end());
}

TEST(Set, function_insert) {
  TestSet tester;
  std::pair<s21::set<int>::iterator, bool> iter_1 =
      tester.s21_set_ten.insert(45);
  std::pair<std::set<int>::iterator, bool> iter_2 =
      tester.std_set_ten.insert(45);
  EXPECT_EQ(*(iter_1.first), *(iter_2.first));
  EXPECT_EQ(iter_1.second, iter_2.second);
}

TEST(Set, function_find_have) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.find(1);
  std::set<int>::iterator j = tester.std_set_ten.find(1);
  EXPECT_EQ(i != tester.s21_set_ten.end(), j != tester.std_set_ten.end());
}

TEST(Set, function_find_dont_have) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.find(100);
  std::set<int>::iterator j = tester.std_set_ten.find(100);
  EXPECT_EQ(i == tester.s21_set_ten.end(), j == tester.std_set_ten.end());
}

TEST(Set, function_erase) {
  TestSet tester;
  tester.s21_set_ten.erase(tester.s21_set_ten.begin());
  tester.std_set_ten.erase(tester.std_set_ten.begin());
  s21::set<int>::iterator iter_1 = tester.s21_set_ten.find(1);
  std::set<int>::iterator iter_2 = tester.std_set_ten.find(1);
  ASSERT_EQ(iter_1 == tester.s21_set_ten.end(),
            iter_2 == tester.std_set_ten.end());
}
TEST(Set, functions_erase_alot) {
  TestSet tester;
  s21::set<int>::iterator it1 = tester.s21_set_ten.find(76);
  std::set<int>::iterator it2 = tester.std_set_ten.find(76);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(123);
  it2 = tester.std_set_ten.find(123);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(43);
  it2 = tester.std_set_ten.find(43);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  ASSERT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}
TEST(Set, function_emplace) {
  TestSet tester;
  auto it1 = tester.s21_set_merge.emplace(2, 3, 5);
  EXPECT_EQ(*it1[0].first, 2);
  EXPECT_EQ(*it1[1].first, 3);
  EXPECT_EQ(*it1[2].first, 5);
}

// MULTISET
class TestMultiset {
 public:
  s21::multiset<int> s21_multiset_empty;
  s21::multiset<int> s21_multiset_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
  s21::multiset<int> s21_multiset_copy;
  std::multiset<int> std_multiset_copy;
  s21::multiset<int> s21_move;
  std::multiset<int> std_move;
  s21::multiset<int> s21_multiset_swap{95, 94, 93, 92};
  std::multiset<int> std_multiset_swap{95, 94, 93, 92};
  s21::multiset<int> s21_multiset_merge{1, 2, 3, 4, 5};
  std::multiset<int> std_multiset_merge{1, 2, 3, 4, 5};

  std::multiset<int> std_multiset_empty;
  std::multiset<int> std_multiset_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
};

TEST(Multiset, constructor_default) {
  TestMultiset tester;
  EXPECT_EQ(tester.s21_multiset_empty.size(), tester.std_multiset_empty.size());
  EXPECT_EQ(tester.s21_multiset_empty.empty(),
            tester.std_multiset_empty.empty());
}

TEST(Multiset, constructor_initialazer) {
  TestMultiset tester;
  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
  EXPECT_EQ(tester.s21_multiset_ten.find(1) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(1) != tester.std_multiset_ten.end());
  EXPECT_EQ(tester.s21_multiset_ten.find(2) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(2) != tester.std_multiset_ten.end());
  EXPECT_EQ(tester.s21_multiset_ten.find(3) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(3) != tester.std_multiset_ten.end());
  EXPECT_EQ(tester.s21_multiset_ten.find(4) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(4) != tester.std_multiset_ten.end());
}

TEST(Multiset, constructor_copy) {
  TestMultiset tester;
  s21::multiset<int> s21_empty(tester.s21_multiset_ten);
  std::multiset<int> std_empty(tester.std_multiset_ten);
  EXPECT_EQ(s21_empty.find(1) != s21_empty.end(),
            std_empty.find(1) != std_empty.end());
  EXPECT_EQ(s21_empty.find(2) != s21_empty.end(),
            std_empty.find(2) != std_empty.end());
  EXPECT_EQ(s21_empty.find(3) != s21_empty.end(),
            std_empty.find(3) != std_empty.end());
  EXPECT_EQ(s21_empty.find(4) != s21_empty.end(),
            std_empty.find(4) != std_empty.end());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  EXPECT_EQ(s21_empty.empty(), std_empty.empty());
}

TEST(Multiset, construct_move) {
  TestMultiset tester;
  s21::multiset<int> s21_move = std::move(tester.s21_multiset_ten);
  std::multiset<int> std_move = std::move(tester.std_multiset_ten);
  EXPECT_EQ(s21_move.find(1) != s21_move.end(),
            std_move.find(1) != std_move.end());
  EXPECT_EQ(s21_move.find(2) != s21_move.end(),
            std_move.find(2) != std_move.end());
  EXPECT_EQ(s21_move.find(3) != s21_move.end(),
            std_move.find(3) != std_move.end());
  EXPECT_EQ(s21_move.find(4) != s21_move.end(),
            std_move.find(4) != std_move.end());
  EXPECT_EQ(s21_move.size(), std_move.size());
  EXPECT_EQ(s21_move.empty(), std_move.empty());
}

TEST(Multiset, operator_move) {
  TestMultiset tester;
  tester.s21_move = std::move(tester.s21_multiset_ten);
  tester.std_move = std::move(tester.std_multiset_ten);
  EXPECT_EQ(tester.s21_move.find(1) != tester.s21_move.end(),
            tester.std_move.find(1) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(2) != tester.s21_move.end(),
            tester.std_move.find(2) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(3) != tester.s21_move.end(),
            tester.std_move.find(3) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(4) != tester.s21_move.end(),
            tester.std_move.find(4) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.size(), tester.std_move.size());
  EXPECT_EQ(tester.s21_move.empty(), tester.std_move.empty());
}

TEST(Multiset, operator_copy) {
  TestMultiset tester;
  tester.s21_multiset_copy = tester.s21_multiset_ten;
  tester.std_multiset_copy = tester.std_multiset_ten;
  EXPECT_EQ(tester.s21_multiset_copy.find(1) != tester.s21_multiset_copy.end(),
            tester.std_multiset_copy.find(1) != tester.std_multiset_copy.end());
  EXPECT_EQ(tester.s21_multiset_copy.find(2) != tester.s21_multiset_copy.end(),
            tester.std_multiset_copy.find(2) != tester.std_multiset_copy.end());
  EXPECT_EQ(tester.s21_multiset_copy.find(3) != tester.s21_multiset_copy.end(),
            tester.std_multiset_copy.find(3) != tester.std_multiset_copy.end());
  EXPECT_EQ(tester.s21_multiset_copy.find(4) != tester.s21_multiset_copy.end(),
            tester.std_multiset_copy.find(4) != tester.std_multiset_copy.end());
  EXPECT_EQ(tester.s21_multiset_copy.size(), tester.std_multiset_copy.size());
  EXPECT_EQ(tester.s21_multiset_copy.empty(), tester.std_multiset_copy.empty());
}

TEST(Multiset, function_not_empty) {
  TestMultiset tester;
  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
  EXPECT_EQ(tester.s21_multiset_ten.empty(), tester.std_multiset_ten.empty());
}

TEST(Multiset, function_empty) {
  TestMultiset tester;
  EXPECT_EQ(tester.s21_multiset_empty.size(), tester.std_multiset_empty.size());
  EXPECT_EQ(tester.s21_multiset_empty.empty(),
            tester.std_multiset_empty.empty());
}

TEST(Multiset, function_size_empty) {
  TestMultiset tester;
  EXPECT_EQ(tester.s21_multiset_empty.size(), tester.std_multiset_empty.size());
}

TEST(Multiset, function_size_not_empty) {
  TestMultiset tester;
  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
}

TEST(Multiset, function_max_sez_empty) {
  TestMultiset tester;
  EXPECT_EQ(tester.s21_multiset_empty.max_size(),
            tester.std_multiset_empty.max_size());
}

TEST(Multiset, function_max_siez_not_empty) {
  TestMultiset tester;
  EXPECT_EQ(tester.s21_multiset_ten.max_size(),
            tester.std_multiset_ten.max_size());
}

TEST(Multiset, function_max_size_float_empty) {
  s21::multiset<float> s21_float_empty;
  std::multiset<float> std_float_empty;
  EXPECT_EQ(s21_float_empty.max_size(), std_float_empty.max_size());
}

TEST(Multiset, function_swap_not_empty) {
  TestMultiset tester;
  tester.s21_multiset_swap.swap(tester.s21_multiset_ten);
  tester.std_multiset_swap.swap(tester.std_multiset_ten);
  EXPECT_EQ(tester.s21_multiset_swap.find(1) != tester.s21_multiset_swap.end(),
            tester.std_multiset_swap.find(1) != tester.std_multiset_swap.end());
  EXPECT_EQ(
      tester.s21_multiset_swap.find(56) != tester.s21_multiset_swap.end(),
      tester.std_multiset_swap.find(56) != tester.std_multiset_swap.end());
  EXPECT_EQ(
      tester.s21_multiset_swap.find(76) != tester.s21_multiset_swap.end(),
      tester.std_multiset_swap.find(76) != tester.std_multiset_swap.end());
  EXPECT_EQ(tester.s21_multiset_ten.find(95) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(95) != tester.std_multiset_ten.end());
  EXPECT_EQ(tester.s21_multiset_ten.find(94) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(94) != tester.std_multiset_ten.end());
  EXPECT_EQ(tester.s21_multiset_ten.find(93) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(93) != tester.std_multiset_ten.end());
  EXPECT_EQ(tester.s21_multiset_swap.size(), tester.std_multiset_swap.size());
  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
}

TEST(Multiset, function_swap_empty) {
  TestMultiset tester;
  tester.s21_multiset_empty.swap(tester.s21_multiset_swap);
  tester.std_multiset_empty.swap(tester.std_multiset_swap);

  EXPECT_EQ(
      tester.s21_multiset_empty.find(95) != tester.s21_multiset_empty.end(),
      tester.std_multiset_empty.find(95) != tester.std_multiset_empty.end());
  EXPECT_EQ(
      tester.s21_multiset_empty.find(94) != tester.s21_multiset_empty.end(),
      tester.std_multiset_empty.find(94) != tester.std_multiset_empty.end());
  EXPECT_EQ(
      tester.s21_multiset_empty.find(93) != tester.s21_multiset_empty.end(),
      tester.std_multiset_empty.find(93) != tester.std_multiset_empty.end());

  EXPECT_EQ(tester.s21_multiset_empty.size(), tester.std_multiset_empty.size());
  EXPECT_EQ(tester.s21_multiset_empty.empty(),
            tester.std_multiset_empty.empty());
  EXPECT_EQ(tester.s21_multiset_swap.size(), tester.std_multiset_swap.size());
  EXPECT_EQ(tester.s21_multiset_swap.empty(), tester.std_multiset_swap.empty());
}
TEST(Multiset, function_merge_with_duplicates) {
  TestMultiset tester;
  tester.s21_multiset_merge.merge(tester.s21_multiset_ten);
  tester.std_multiset_merge.merge(tester.std_multiset_ten);

  EXPECT_EQ(
      tester.s21_multiset_merge.find(1) != tester.s21_multiset_merge.end(),
      tester.std_multiset_merge.find(1) != tester.std_multiset_merge.end());
  EXPECT_EQ(
      tester.s21_multiset_merge.find(2) != tester.s21_multiset_merge.end(),
      tester.std_multiset_merge.find(2) != tester.std_multiset_merge.end());
  EXPECT_EQ(
      tester.s21_multiset_merge.find(76) != tester.s21_multiset_merge.end(),
      tester.std_multiset_merge.find(76) != tester.std_multiset_merge.end());

  EXPECT_EQ(tester.s21_multiset_merge.size(), tester.std_multiset_merge.size());
  EXPECT_EQ(tester.std_multiset_merge.empty(),
            tester.std_multiset_merge.empty());
}

TEST(Multiset, function_merge_wihout_duplicates) {
  TestMultiset tester;
  tester.s21_multiset_ten.merge(tester.s21_multiset_swap);
  tester.std_multiset_ten.merge(tester.std_multiset_swap);

  EXPECT_EQ(tester.s21_multiset_ten.find(95) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(95) != tester.std_multiset_ten.end());
  EXPECT_EQ(tester.s21_multiset_ten.find(1) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(1) != tester.std_multiset_ten.end());
  EXPECT_EQ(tester.s21_multiset_ten.find(94) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(94) != tester.std_multiset_ten.end());
  EXPECT_EQ(tester.s21_multiset_ten.find(76) != tester.s21_multiset_ten.end(),
            tester.std_multiset_ten.find(76) != tester.std_multiset_ten.end());

  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
  EXPECT_EQ(tester.std_multiset_ten.empty(), tester.std_multiset_ten.empty());
  EXPECT_EQ(tester.s21_multiset_swap.size(), tester.std_multiset_swap.size());
  EXPECT_EQ(tester.s21_multiset_swap.empty(), tester.std_multiset_swap.empty());
}

TEST(Multiset, function_clear_not_empty) {
  TestMultiset tester;
  tester.s21_multiset_ten.clear();
  tester.std_multiset_ten.clear();
  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
  EXPECT_EQ(tester.s21_multiset_ten.empty(), tester.std_multiset_ten.empty());
}

TEST(Multiset, function_clear_empty) {
  TestMultiset tester;
  tester.s21_multiset_empty.clear();
  tester.std_multiset_empty.clear();
  EXPECT_EQ(tester.s21_multiset_empty.size(), tester.std_multiset_empty.size());
  EXPECT_EQ(tester.std_multiset_empty.empty(),
            tester.std_multiset_empty.empty());
}

TEST(Multiset, function_begin_not_empty) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_ten.begin();
  std::multiset<int>::iterator j = tester.std_multiset_ten.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Multiset, function_begin_empty) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_empty.begin();
  std::multiset<int>::iterator j = tester.std_multiset_empty.begin();
  EXPECT_EQ(*i, *j);
}
TEST(Multiset, function_const_begin_not_empty) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_ten.begin();
  std::multiset<int>::iterator j = tester.std_multiset_ten.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Multiset, function_const_begin_empty) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_empty.begin();
  std::multiset<int>::iterator j = tester.std_multiset_empty.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Multiset, function_end_empty) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_empty.end();
  std::multiset<int>::iterator j = tester.std_multiset_empty.end();
  EXPECT_EQ(*i, *j);
}

TEST(Multiset, function_const_end_empty) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_empty.end();
  std::multiset<int>::iterator j = tester.std_multiset_empty.end();
  EXPECT_EQ(*i, *j);
}
TEST(Multiset, operator_plus) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_ten.begin();
  std::multiset<int>::iterator j = tester.std_multiset_ten.begin();
  while (i != tester.s21_multiset_ten.end() &&
         j != tester.std_multiset_ten.end()) {
    EXPECT_EQ(*i, *j);
    ++i;
    ++j;
  }
  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
  EXPECT_EQ(tester.std_multiset_ten.empty(), tester.std_multiset_ten.empty());
}

TEST(Multiset, operator_minus) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_ten.rbegin();
  std::multiset<int>::iterator j = --tester.std_multiset_ten.end();
  while (i != tester.s21_multiset_ten.begin() &&
         j != tester.std_multiset_ten.begin()) {
    --i;
    --j;
    EXPECT_EQ(*i, *j);
  }
  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
  EXPECT_EQ(tester.s21_multiset_ten.empty(), tester.std_multiset_ten.empty());
}

TEST(Multiset, operation_assignment) {
  TestMultiset tester;
  s21::multiset<int>::iterator iter_1 = tester.s21_multiset_ten.begin();
  s21::multiset<int>::iterator iter_3 = iter_1;
  std::multiset<int>::iterator iter_2 = tester.std_multiset_ten.begin();
  std::multiset<int>::iterator iter_4 = iter_2;
  ASSERT_EQ(*iter_1, *iter_3);
  ASSERT_EQ(*iter_2, *iter_4);
}
TEST(Multiset, operation_equal) {
  TestMultiset tester;
  s21::multiset<int>::iterator it1 = tester.s21_multiset_ten.begin();
  s21::multiset<int>::iterator it3 = tester.s21_multiset_ten.begin();
  std::multiset<int>::iterator it2 = tester.std_multiset_ten.begin();
  std::multiset<int>::iterator it4 = tester.std_multiset_ten.begin();
  ASSERT_EQ(it1 == it3, it2 == it4);
}
TEST(Multiset, operation_not_equal) {
  TestMultiset tester;
  s21::multiset<int>::iterator iter_1 = tester.s21_multiset_ten.begin();
  std::multiset<int>::iterator iter_2 = tester.std_multiset_ten.begin();
  ASSERT_EQ(iter_1 != tester.s21_multiset_ten.end(),
            iter_2 != tester.std_multiset_ten.end());
}

TEST(Multiset, function_insert) {
  TestMultiset tester;
  tester.s21_multiset_ten.insert(45);
  tester.std_multiset_ten.insert(45);
  EXPECT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
  EXPECT_EQ(tester.s21_multiset_ten.empty(), tester.std_multiset_ten.empty());
}

TEST(Multiset, function_find_have) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_ten.find(1);
  std::multiset<int>::iterator j = tester.std_multiset_ten.find(1);
  EXPECT_EQ(i != tester.s21_multiset_ten.end(),
            j != tester.std_multiset_ten.end());
}

TEST(Multiset, function_find_dont_have) {
  TestMultiset tester;
  s21::multiset<int>::iterator i = tester.s21_multiset_ten.find(100);
  std::multiset<int>::iterator j = tester.std_multiset_ten.find(100);
  EXPECT_EQ(i == tester.s21_multiset_ten.end(),
            j == tester.std_multiset_ten.end());
}

TEST(Multiset, function_erase) {
  TestMultiset tester;
  tester.s21_multiset_ten.erase(tester.s21_multiset_ten.begin());
  tester.std_multiset_ten.erase(tester.std_multiset_ten.begin());
  s21::multiset<int>::iterator iter_1 = tester.s21_multiset_ten.find(1);
  std::multiset<int>::iterator iter_2 = tester.std_multiset_ten.find(1);
  ASSERT_EQ(iter_1 == tester.s21_multiset_ten.end(),
            iter_2 == tester.std_multiset_ten.end());
}
TEST(Multiset, functions_erase_alot) {
  TestMultiset tester;
  s21::multiset<int>::iterator it1 = tester.s21_multiset_ten.find(76);
  std::multiset<int>::iterator it2 = tester.std_multiset_ten.find(76);
  tester.s21_multiset_ten.erase(it1);
  tester.std_multiset_ten.erase(it2);
  it1 = tester.s21_multiset_ten.find(123);
  it2 = tester.std_multiset_ten.find(123);
  tester.s21_multiset_ten.erase(it1);
  tester.std_multiset_ten.erase(it2);
  it1 = tester.s21_multiset_ten.find(43);
  it2 = tester.std_multiset_ten.find(43);
  tester.s21_multiset_ten.erase(it1);
  tester.std_multiset_ten.erase(it2);
  ASSERT_EQ(tester.s21_multiset_ten.size(), tester.std_multiset_ten.size());
}
TEST(Multiset, function_emplace) {
  TestMultiset tester;
  auto it1 = tester.s21_multiset_merge.emplace(2, 3, 5);
  EXPECT_EQ(*it1[0].first, 2);
  EXPECT_EQ(*it1[1].first, 3);
  EXPECT_EQ(*it1[2].first, 5);
}

TEST(Multiset, function_count) {
  s21::multiset<int> s1({1, 3, 4, 2, 2});
  std::multiset<int> s2({1, 3, 4, 2, 2});
  ASSERT_EQ(s1.count(2), s2.count(2));
  ASSERT_EQ(s1.count(3), s2.count(3));
}

TEST(Multiset, function_contains) {
  TestMultiset tester;
  ASSERT_TRUE(tester.s21_multiset_ten.contains(1));
  ASSERT_TRUE(tester.s21_multiset_ten.contains(2));
  ASSERT_TRUE(tester.s21_multiset_ten.contains(56));
  ASSERT_TRUE(tester.s21_multiset_ten.contains(76));
}
TEST(Multiset, function_lower_bound) {
  s21::multiset<int> s1({1, 3, 4, 2, 2});
  std::multiset<int> s2({1, 3, 4, 2, 2});
  s21::multiset<int>::iterator it1 = s1.lower_bound(2);
  std::multiset<int>::iterator it2 = s2.lower_bound(2);
  ASSERT_EQ(*it1, *it2);
  ++it1;
  ++it2;
  ASSERT_EQ(*it1, *it2);
  ++it1;
  ++it2;
  ASSERT_EQ(*it1, *it2);
  --it1;
  --it2;
  --it1;
  --it2;
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
}
TEST(Multiset, function_upper_bound) {
  s21::multiset<int> s1({1, 3, 4, 2, 2});
  std::multiset<int> s2({1, 3, 4, 2, 2});
  s21::multiset<int>::iterator it1 = s1.upper_bound(2);
  std::multiset<int>::iterator it2 = s2.upper_bound(2);
  ASSERT_EQ(*it1, *it2);
  ++it1;
  ++it2;
  ASSERT_EQ(*it1, *it2);
  --it1;
  --it2;
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
}
TEST(Multiset, function_equal_range) {
  s21::multiset<int> s1({1, 3, 4, 2, 2});
  std::multiset<int> s2({1, 3, 4, 2, 2});
  auto it1 = s1.equal_range(2);
  auto it2 = s2.equal_range(2);
  ASSERT_EQ(*it1.first, *it2.first);
  ASSERT_EQ(*it1.second, *it2.second);
}

// MAP
class TestMap {
 public:
  s21::map<int, int> s21_map_empty;
  s21::map<int, int> s21_map_four{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21::map<int, int> s21_map_swap{{1, 95}, {2, 94}, {3, 93}};

  std::map<int, int> std_map_empty;
  std::map<int, int> std_map_four{{
                                      1,
                                      1,
                                  },
                                  {2, 2},
                                  {3, 3},
                                  {4, 4}};
  std::map<int, int> std_map_swap{{1, 95}, {2, 95}, {3, 95}};
};

TEST(Map, construcor_default) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}

TEST(Map, construcot_initializer) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
  EXPECT_EQ(tester.s21_map_four[4], tester.std_map_four[4]);
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.std_map_four.empty(), tester.std_map_four.empty());
}

TEST(Map, constructor_copy_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy(tester.s21_map_empty);
  std::map<int, int> std_map_copy(tester.std_map_empty);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(std_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, constructor_copy_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy(tester.s21_map_four);
  std::map<int, int> std_map_copy(tester.std_map_four);
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(std_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, constructor_move_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move = std::move(tester.s21_map_empty);
  std::map<int, int> std_map_move = std::move(tester.std_map_empty);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, constructor_move_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move = std::move(tester.s21_map_four);
  std::map<int, int> std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(s21_map_move[4], std_map_move[4]);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, operator_copy_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy;
  std::map<int, int> std_map_copy;
  s21_map_copy = tester.s21_map_four;
  std_map_copy = tester.std_map_four;
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, operator_copy_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy{{1, 1}, {2, 2}};
  std::map<int, int> std_map_copy{{1, 1}, {2, 2}};
  s21_map_copy = tester.s21_map_four;
  std_map_copy = tester.std_map_four;
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, operator_move_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move;
  std::map<int, int> std_map_move;
  s21_map_move = std::move(tester.s21_map_four);
  std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(std_map_move[4], std_map_move[4]);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, operator_move_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move{{1, 1}, {2, 2}};
  std::map<int, int> std_map_move{{1, 1}, {2, 2}};
  s21_map_move = std::move(tester.s21_map_empty);
  std_map_move = std::move(tester.std_map_empty);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(s21_map_move[2], std_map_move[2]);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, function_empty_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(tester.s21_map_empty[1], tester.std_map_empty[1]);
}

TEST(Map, function_empty_not_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
}

TEST(Map, function_size_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(tester.s21_map_empty[1], tester.std_map_empty[1]);
}

TEST(Map, function_size_not_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.std_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
  EXPECT_EQ(tester.s21_map_four[4], tester.std_map_four[4]);
}

TEST(Map, function_max_size_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(tester.s21_map_empty.max_size(), tester.std_map_empty.max_size());
}

TEST(Map, function_swap_empty) {
  s21::map<int, int> m1({{1, 8}, {4, 2}, {2, 3}});
  s21::map<int, int> m2;
  m1.swap(m2);

  std::map<int, int> m3({{1, 8}, {4, 2}, {2, 3}});
  std::map<int, int> m4;
  m3.swap(m4);

  ASSERT_EQ(m2[1], m4[1]);
  ASSERT_EQ(m2[2], m4[2]);
  ASSERT_EQ(m2[4], m4[4]);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}

TEST(Map, function_swap_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_swap{{1, 1}, {2, 2}};
  std::map<int, int> std_map_swap{{1, 1}, {2, 2}};
  s21_map_swap.swap(tester.s21_map_four);
  std_map_swap.swap(tester.std_map_four);
  EXPECT_EQ(s21_map_swap[1], std_map_swap[1]);
  EXPECT_EQ(s21_map_swap[4], std_map_swap[4]);
  EXPECT_EQ(s21_map_swap.size(), std_map_swap.size());
  EXPECT_EQ(s21_map_swap.empty(), std_map_swap.empty());
}

TEST(Map, WithDuplicatesCase) {
  s21::map<int, int> m1({{1, 8}, {4, 2}, {2, 3}});
  s21::map<int, int> m2({{1, 3}, {2, 2}});
  m1.merge(m2);

  std::map<int, int> m3({{1, 8}, {4, 2}, {2, 3}});
  std::map<int, int> m4({{1, 3}, {2, 2}});
  m3.merge(m4);

  ASSERT_EQ(m1[1], m3[1]);
  ASSERT_EQ(m1[2], m3[2]);
  ASSERT_EQ(m1[4], m3[4]);

  ASSERT_EQ(m2[1], m4[1]);
  ASSERT_EQ(m2[2], m4[2]);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}
TEST(Map, WithoutDuplicatesCase) {
  s21::map<int, int> m1({{1, 2}, {3, 4}, {4, 5}});
  s21::map<int, int> m2({{5, 6}, {7, 7}});
  m1.merge(m2);

  std::map<int, int> m3({{1, 2}, {3, 4}, {4, 5}});
  std::map<int, int> m4({{5, 6}, {7, 7}});
  m3.merge(m4);

  ASSERT_EQ(m1[1], m3[1]);
  ASSERT_EQ(m1[3], m3[3]);
  ASSERT_EQ(m1[4], m3[4]);
  ASSERT_EQ(m1[5], m3[5]);
  ASSERT_EQ(m1[7], m3[7]);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}

TEST(Map, function_clear_empty) {
  TestMap tester;
  tester.s21_map_empty.clear();
  tester.std_map_empty.clear();
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}

TEST(Map, function_clear_not_empty) {
  TestMap tester;
  tester.s21_map_four.clear();
  tester.std_map_four.clear();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
}

TEST(Map, function_begin_empty) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_empty.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  EXPECT_EQ(iter_1 == tester.s21_map_empty.end(),
            iter_2 == tester.std_map_empty.end());
}

TEST(Map, function_begin_not_empty) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_four.end());
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, const_begin_empty) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_empty.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == tester.s21_map_empty.end(),
            iter_2 == tester.std_map_empty.end());
}
TEST(Map, const_begin_not_empty) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_four.end());
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, operator_plus) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, operator_minus) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  --iter_1;
  --iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, operator_assignment) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::iterator iter_3 = iter_1;
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  std::map<int, int>::iterator iter_4 = iter_2;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*iter_1).second, (*iter_3).second);
  EXPECT_EQ((*iter_2).second, (*iter_4).second);
}
TEST(Map, operator_equal) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::iterator iter_3 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  std::map<int, int>::iterator iter_4 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == iter_3, iter_2 == iter_4);
}
TEST(Map, operatort_not_equal) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_empty.end());
}
TEST(Map, const_operator_plus) {
  TestMap tester;
  s21::map<int, int>::const_iterator iter_1 = tester.s21_map_four.cbegin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.cbegin();
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, const_operator_minus) {
  TestMap tester;
  s21::map<int, int>::const_iterator iter_1 = tester.s21_map_four.cbegin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.cbegin();
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  --iter_1;
  --iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, const_operator_assignment) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::iterator iter_3 = iter_1;
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  std::map<int, int>::iterator iter_4 = iter_2;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*iter_1).second, (*iter_3).second);
  EXPECT_EQ((*iter_2).second, (*iter_4).second);
}
TEST(Map, const_operator_equal) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::iterator iter_3 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  std::map<int, int>::iterator iter_4 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == iter_3, iter_2 == iter_4);
}
TEST(Map, const_operatort_not_equal) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_empty.end());
}

TEST(Map, function_insert_without_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert({5, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({5, 2});
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_with_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert({1, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 2});
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_without_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert(7, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({7, 7});
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_with_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert(1, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 7});
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_or_assign_value) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  s21::map<int, int> m2({{1, 3}, {4, 2}});
  std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert_or_assign(5, 2);
  std::pair<s21::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(5, 2);
  ASSERT_TRUE(it1.second == it2.second);
}

TEST(Map, function_insert_or_assign) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  s21::map<int, int> m2({{1, 3}, {4, 2}});
  std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert_or_assign(1, 2);
  std::pair<s21::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(1, 2);
  ASSERT_EQ((*(it1.first)).second, (*(it2.first)).second);
  ASSERT_TRUE(it1.second == it2.second);
}

TEST(Map, function_insert_s) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert(5, 2);
  ASSERT_EQ((*(it1.first)).second, 2);
  ASSERT_TRUE(it1.second);
}

TEST(Map, function_at) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  ASSERT_EQ(m1.at(1), m2.at(1));
}
TEST(Map, function_erase) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  ASSERT_EQ(m1[1], m2[1]);
}
TEST(Map, function_Emplace) {
  s21::map<int, int> s1({{1, 3}, {4, 2}});
  auto it1 = s1.emplace(std::pair<int, int>(5, 5), std::pair<int, int>(51, 53));
  ASSERT_EQ((*it1[0].first).second, 5);
  ASSERT_EQ((*it1[1].first).second, 53);
}
TEST(Map, function_ontains) {
  s21::map<int, int> s1({{1, 3}, {4, 2}});
  ASSERT_TRUE(s1.contains(1));
  ASSERT_TRUE(s1.contains(4));
  ASSERT_FALSE(s1.contains(3));
}

}  // namespace s21

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}