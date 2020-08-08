#ifndef POCO_EXAMPLES_PROPERTY_H
#define POCO_EXAMPLES_PROPERTY_H

#define PATIENT_PROPERTY() \
std::make_tuple( \
    property(&Patient::pat_id_issuer, "IssuerOfPatientID", "pat_id_issuer"),\
    property(&Patient::pat_name, "PatientName", "pat_name"),\
    property(&Patient::pat_id, "PatientID", "pat_id"),\
    property(&Patient::pat_birthdate, "PatientBirthDate", "pat_birthdate"),\
    property(&Patient::pat_sex, "PatientSex", "pat_sex"),\
    property(&Patient::merge_fk, "NONE", "merge_fk")\
)

#endif //POCO_EXAMPLES_PROPERTY_H
