#include "fpx_cpp-utils.h"

#define FPX_GENERIC_ERRMSG "An exception has occured at runtime!"
#define FPX_NOTIMPLEMENTED_ERRMSG "This functionality has not been implemented yet!"

namespace fpx {

  // method/constructor declarations for the GENERIC exception class
  Exception::Exception(): m_ErrMessage(FPX_GENERIC_ERRMSG), m_ErrCode(-1) { }
  Exception::Exception(int code): m_ErrMessage(FPX_GENERIC_ERRMSG), m_ErrCode(code) { }
  Exception::Exception(const char* message): m_ErrMessage(message), m_ErrCode(-1) { }
  Exception::Exception(const char* message, int code): m_ErrMessage(message), m_ErrCode(code) { }

  int Exception::Code() const { return m_ErrCode; }
  const char* Exception::Message() const { return m_ErrMessage; }

  // method/constructor declarations for the NotImplementedException class
  NotImplementedException::NotImplementedException(): m_ErrMessage(FPX_NOTIMPLEMENTED_ERRMSG), m_ErrCode(-2) { }
  NotImplementedException::NotImplementedException(int code): m_ErrMessage(FPX_NOTIMPLEMENTED_ERRMSG), m_ErrCode(code) { }
  NotImplementedException::NotImplementedException(const char* message): m_ErrMessage(message), m_ErrCode(-1) { }
  NotImplementedException::NotImplementedException(const char* message, int code): m_ErrMessage(message), m_ErrCode(code) { }

  int NotImplementedException::Code() const { return m_ErrCode; }
  const char* NotImplementedException::Message() const { return m_ErrMessage; }

}