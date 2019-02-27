class Brackets
{
public:
  enum class Errors
  {
    OK,
    INVALID_SEQUENCE
  };

  Brackets(std::string&& data);
  virtual Errors checkData();
  virtual ~Brackets() = default;

private:
  std::string m_data;
};
