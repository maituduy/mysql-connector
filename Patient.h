#ifndef POCO_EXAMPLES_PATIENT_H
#define POCO_EXAMPLES_PATIENT_H

#include <cstdint>
#include <string>

#include "Type.h"

#include "Property.h"
#include <json/json.h>

#include "Util.h"

using namespace Util;


namespace database {
    class Patient{

    public:
        std::uint64_t pk = -1;
        std::uint64_t merge_fk = -1;
        std::string pat_id_issuer;
        std::string pat_name;
        std::string pat_id;
        std::string pat_fn_sx;
        std::string pat_gn_sx;
        std::string pat_i_name;
        std::string pat_p_name;
        std::string pat_birthdate;
        std::string pat_sex;
        std::string pat_custom1;
        std::string pat_custom2;
        std::string pat_custom3;
        Type::DateTime updated_time;
        Type::DateTime created_time;
        Type::Blob pat_attrs;
    public:
        uint64_t getPk() const;

        void setPk(uint64_t pk);

        uint64_t getMergeFk() const;

        void setMergeFk(uint64_t mergeFk);

        const std::string &getPatIdIssuer() const;

        void setPatIdIssuer(const std::string &patIdIssuer);

        const std::string &getPatName() const;

        void setPatName(const std::string &patName);

        const std::string &getPatId() const;

        void setPatId(const std::string &patId);

        const std::string &getPatFnSx() const;

        void setPatFnSx(const std::string &patFnSx);

        const std::string &getPatGnSx() const;

        void setPatGnSx(const std::string &patGnSx);

        const std::string &getPatIName() const;

        void setPatIName(const std::string &patIName);

        const std::string &getPatPName() const;

        void setPatPName(const std::string &patPName);

        const std::string &getPatBirthdate() const;

        void setPatBirthdate(const std::string &patBirthdate);

        const std::string &getPatSex() const;

        void setPatSex(const std::string &patSex);

        const std::string &getPatCustom1() const;

        void setPatCustom1(const std::string &patCustom1);

        const std::string &getPatCustom2() const;

        void setPatCustom2(const std::string &patCustom2);

        const std::string &getPatCustom3() const;

        void setPatCustom3(const std::string &patCustom3);

        const Type::DateTime &getUpdatedTime() const;

        void setUpdatedTime(const Type::DateTime &updatedTime);

        const Type::DateTime &getCreatedTime() const;

        void setCreatedTime(const Type::DateTime &createdTime);

        const Type::Blob &getPatAttrs() const;

        void setPatAttrs(const Type::Blob &patAttrs);

    private:

        const static std::string insertQuery;

    public:
        constexpr static auto tableName = "patient";

        Patient();

        std::uint64_t save();

        static std::size_t getPropertiesSize();

        static auto getProperties() -> const decltype(PATIENT_PROPERTY()) &;

        void fromJson(Json::Value &jsonVal);

        void toJson(Json::Value *jsonVal);
    };
}

#endif //POCO_EXAMPLES_PATIENT_H
