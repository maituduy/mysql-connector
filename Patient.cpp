#include "Patient.h"
#include "Config.h"
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>

#include "QueryFunctor.h"

namespace database {

    std::string createInsertQuery() {
        functor::CreateInsertQuery<Patient> ciq;
        Util::for_each_in_tuple(Patient::getProperties() , ciq);
        return ciq.query;
    }

    const std::string Patient::insertQuery = createInsertQuery();

    Patient::Patient() {

    }

    std::uint64_t Patient::save() {
        sql::PreparedStatement *pStatement(con.connection->prepareStatement(insertQuery));
        Util::for_each_in_tuple(getProperties(), functor::SaveFunctor<Patient>{pStatement, this});
//        pStatement->executeQuery();
    }

    auto Patient::getProperties() -> const decltype(PATIENT_PROPERTY()) & {
        constexpr static auto pp = PATIENT_PROPERTY();
        return pp;
    }

    std::size_t Patient::getPropertiesSize() {
        return Util::size(getProperties());
    }

    uint64_t Patient::getPk() const {
        return pk;
    }

    void Patient::setPk(uint64_t pk) {
        Patient::pk = pk;
    }

    uint64_t Patient::getMergeFk() const {
        return merge_fk;
    }

    void Patient::setMergeFk(uint64_t mergeFk) {
        merge_fk = mergeFk;
    }

    const std::string &Patient::getPatIdIssuer() const {
        return pat_id_issuer;
    }

    void Patient::setPatIdIssuer(const std::string &patIdIssuer) {
        pat_id_issuer = patIdIssuer;
    }

    const std::string &Patient::getPatName() const {
        return pat_name;
    }

    void Patient::setPatName(const std::string &patName) {
        pat_name = patName;
    }

    const std::string &Patient::getPatId() const {
        return pat_id;
    }

    void Patient::setPatId(const std::string &patId) {
        pat_id = patId;
    }

    const std::string &Patient::getPatFnSx() const {
        return pat_fn_sx;
    }

    void Patient::setPatFnSx(const std::string &patFnSx) {
        pat_fn_sx = patFnSx;
    }

    const std::string &Patient::getPatGnSx() const {
        return pat_gn_sx;
    }

    void Patient::setPatGnSx(const std::string &patGnSx) {
        pat_gn_sx = patGnSx;
    }

    const std::string &Patient::getPatIName() const {
        return pat_i_name;
    }

    void Patient::setPatIName(const std::string &patIName) {
        pat_i_name = patIName;
    }

    const std::string &Patient::getPatPName() const {
        return pat_p_name;
    }

    void Patient::setPatPName(const std::string &patPName) {
        pat_p_name = patPName;
    }

    const std::string &Patient::getPatBirthdate() const {
        return pat_birthdate;
    }

    void Patient::setPatBirthdate(const std::string &patBirthdate) {
        pat_birthdate = patBirthdate;
    }

    const std::string &Patient::getPatSex() const {
        return pat_sex;
    }

    void Patient::setPatSex(const std::string &patSex) {
        pat_sex = patSex;
    }

    const std::string &Patient::getPatCustom1() const {
        return pat_custom1;
    }

    void Patient::setPatCustom1(const std::string &patCustom1) {
        pat_custom1 = patCustom1;
    }

    const std::string &Patient::getPatCustom2() const {
        return pat_custom2;
    }

    void Patient::setPatCustom2(const std::string &patCustom2) {
        pat_custom2 = patCustom2;
    }

    const std::string &Patient::getPatCustom3() const {
        return pat_custom3;
    }

    void Patient::setPatCustom3(const std::string &patCustom3) {
        pat_custom3 = patCustom3;
    }

    const Type::DateTime &Patient::getUpdatedTime() const {
        return updated_time;
    }

    void Patient::setUpdatedTime(const Type::DateTime &updatedTime) {
        updated_time = updatedTime;
    }

    const Type::DateTime &Patient::getCreatedTime() const {
        return created_time;
    }

    void Patient::setCreatedTime(const Type::DateTime &createdTime) {
        created_time = createdTime;
    }

    const Type::Blob &Patient::getPatAttrs() const {
        return pat_attrs;
    }

    void Patient::setPatAttrs(const Type::Blob &patAttrs) {
        pat_attrs = patAttrs;
    }

    void Patient::fromJson(Json::Value &jsonVal) {
        Util::for_each_in_tuple(getProperties(), functor::FromJsonFunctor<Patient>{this, jsonVal});
    }

    void Patient::toJson(Json::Value *jsonVal) {
        Util::for_each_in_tuple(getProperties(), functor::ToJsonFunctor<Patient>{this, jsonVal});
    }
}

