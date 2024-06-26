#ifndef FPX_CPPUTILS_H
#define FPX_CPPUTILS_H

namespace fpx {

  // Custom exceptions declared below
  class Exception {
    public:
      Exception();
      Exception(int);
      Exception(const char*);
      Exception(const char*, int);

      virtual int Code() const;
      virtual const char* Message() const;

    protected:
      int m_ErrCode;
      const char* m_ErrMessage;
  };

  class NotImplementedException : public Exception {
    public:
      NotImplementedException();
      NotImplementedException(int);
      NotImplementedException(const char*);
      NotImplementedException(const char*, int);

      int Code() const;
      const char* Message() const;

    private:
      int m_ErrCode;
      const char* m_ErrMessage;
  };

}

#endif /* FPX_CPPUTILS_H */