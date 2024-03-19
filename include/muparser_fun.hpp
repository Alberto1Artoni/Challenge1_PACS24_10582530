#include <muParser.h>
#include <memory>
#include <string>

class MuparserFun
{
public:

  MuparserFun(const std::string &s):
    m_expression(s)
  {
    try
      {
        m_parser.DefineVar("x1", &m_var1);
        m_parser.DefineVar("x2", &m_var2);
        m_parser.SetExpr(m_expression);
      }
    catch (mu::Parser::exception_type &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
  };

  double operator()(const double &x1, const double &x2)
  {
    m_var1 = x1;
    m_var2 = x2;
    double y = m_parser.Eval();
    return y;
  };

private:
  std::string m_expression;
  double     m_var1, m_var2;
  mu::Parser m_parser;
};
