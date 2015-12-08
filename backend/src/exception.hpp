#include <ast.hpp>
#include <stdexcept>

class TermException : public std::runtime_error {
public:
  TermException(const ast::Term *const term, const ast::Type *const type);
private:
  const ast::Term *const term_;
  const ast::Term *const type_;
};

class TypeNotMatch : public TermException {
public:
  TypeNotMatch(const TermException &exception, const ast::Type *const expect);
private:
  const ast::Type *const expect_;
};

class NotFunction : public TermException {
public:
  NotFunction(const ast::Term *const term, const ast::Type *const type);
};
