#include <muParser.h>
#include <memory>
#include <string>

class MuparserFun
{
public:
  MuparserFun(const MuparserFun &m)
    : m_parser(m.m_parser)
  {
    m_parser.DefineVar("x1", &m_var1);
    m_parser.DefineVar("x2", &m_var2);
  };

  MuparserFun(const std::string &s)
  {
    try
      {
        m_parser.DefineVar("x1", &m_var1);
        m_parser.DefineVar("x2", &m_var2);
        m_parser.SetExpr(s);
      }
    catch (mu::Parser::exception_type &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
  };

  double
  operator()(const double &x1, const double &x2)
  {
    m_var1 = x1;
    m_var2 = x2;
    double y = m_parser.Eval();
    return y;
  };

private:
  double     m_var1, m_var2;
  mu::Parser m_parser;
};
