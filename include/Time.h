class Time : public Converter {
public:
    double convert(double value,
                   const std::string& from,
                   const std::string& to) override;
};
