//
// Created by 4c3y (acey) on 12.09.22.
//

#include "test_utils.h"
#include <gtest/gtest.h>
#include <log++.h>

using namespace lpp::rostest;

TEST(default_basic, glog_syntax_severity_debug) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(DLOG(INFO) << "xyz");

  ASSERT_TRUE(isSubstring(output, "xyz"));
  ASSERT_TRUE(isSubstring(output, "test_default_basic.cc"));

  ASSERT_EQ(output[0], 'I');
}

TEST(default_basic, glog_syntax_severity_info) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(LOG(INFO) << "xyz");

  ASSERT_TRUE(isSubstring(output, "xyz"));
  ASSERT_TRUE(isSubstring(output, "test_default_basic.cc"));

  ASSERT_EQ(output[0], 'I');
}

TEST(default_basic, glog_syntax_severity_warning) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(LOG(WARNING) << "xyz");

  ASSERT_TRUE(isSubstring(output, "xyz"));
  ASSERT_TRUE(isSubstring(output, "test_default_basic.cc"));
  ASSERT_EQ(output[0], 'W');
}

TEST(default_basic, glog_syntax_severity_error) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(LOG(ERROR) << "xyz");

  ASSERT_TRUE(isSubstring(output, "xyz"));
  ASSERT_TRUE(isSubstring(output, "test_default_basic.cc"));
  ASSERT_EQ(output[0], 'E');
}

TEST(default_basic, glog_syntax_severity_fatal) {
  LOG_INIT(*test_argv);
  ASSERT_TRUE(checkAbort([](){LPP_CAPTURE_STDERR(LOG(FATAL) << "xyz");}));
}

TEST(default_basic, lpp_syntax_severity_debug) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDOUT(LOG(D, "Test" << 123));
  ASSERT_EQ(output, "DEBUG Test123\n");
}

TEST(default_basic, lpp_syntax_severity_info) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDOUT(LOG(I, "Test" << 123));
  ASSERT_EQ(output, "INFO  Test123\n");
}

TEST(default_basic, lpp_syntax_severity_warning) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDOUT(LOG(W, "Test" << 123));
  ASSERT_EQ(output, "WARN  Test123\n");
}

TEST(default_basic, lpp_syntax_severity_error) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDOUT(LOG(E, "Test" << 123));
  ASSERT_EQ(output, "ERROR Test123\n");
}

TEST(default_basic, lpp_syntax_severity_fatal) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDOUT(LOG(F, "Test" << 123));
  ASSERT_EQ(output, "FATAL Test123\n");
}

TEST(default_basic, roslog_syntax_severity_debug) {
  LOG_INIT(*test_argv);

  std::string output1 = LPP_CAPTURE_STDOUT(ROS_DEBUG("Test"));
  ASSERT_EQ(debug, removeNumbersFromString(output1));
}

TEST(default_basic, roslog_syntax_severity_debug_stream) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDOUT(ROS_DEBUG_STREAM("Test"));
  ASSERT_EQ(debug, removeNumbersFromString(output));
}

TEST(default_basic, roslog_syntax_severity_info) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDOUT(ROS_INFO("Test"));
  ASSERT_EQ(info, removeNumbersFromString(output));
}

TEST(default_basic, roslog_syntax_severity_info_stream) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDOUT(ROS_INFO_STREAM("Test"));
  ASSERT_EQ(info, removeNumbersFromString(output));
}

TEST(default_basic, roslog_syntax_severity_warning) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(ROS_WARN("Test"));
  ASSERT_EQ(warning, removeNumbersFromString(output));
}

TEST(default_basic, roslog_syntax_severity_warning_stream) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(ROS_WARN_STREAM("Test"));
  ASSERT_EQ(warning, removeNumbersFromString(output));
}

TEST(default_basic, roslog_syntax_severity_error) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(ROS_ERROR("Test"));
  ASSERT_EQ(error, removeNumbersFromString(output));
}

TEST(default_basic, roslog_syntax_severity_error_stream) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(ROS_ERROR_STREAM("" << "Test"));
  ASSERT_EQ(error, removeNumbersFromString(output));
}

TEST(default_basic, roslog_syntax_severity_fatal) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(ROS_FATAL("Test"));
  ASSERT_EQ(fatal, removeNumbersFromString(output));

}

TEST(default_basic, roslog_syntax_severity_fatal_stream) {
  LOG_INIT(*test_argv);

  std::string output = LPP_CAPTURE_STDERR(ROS_FATAL_STREAM("" << "Test"));
  ASSERT_EQ(fatal, removeNumbersFromString(output));
}
