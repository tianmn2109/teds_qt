#include "domparser.h"
#include <QFile>
#include <iostream>
using namespace std;

DomParser::DomParser()
{
    //treeWidget = tree;
    meta = new Meta_TEDS();
    phy = new Phy_TEDS();
    ts = new Transducerchannel_TEDS();
}

bool DomParser::readMetaTedsFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        cerr << "Error: Cannot reaf file" << qPrintable(filename)
            << ": "  << qPrintable(file.errorString())
            << endl;
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;


    if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        cerr << "Error: parse error at line " << errorLine << " , "
            << "column " << errorColumn << " : "
            << qPrintable(errorStr) << endl;
        return false;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "meta_teds")
    {
        cerr << "Error : Not a valid meta teds file" << endl;
        return false;
    }
    parseMetaTeds(root);

    // cout << root. << endl;
    return true;
}


bool DomParser::readPhyTedsFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        cerr << "Error: Cannot reaf file" << qPrintable(filename)
            << ": "  << qPrintable(file.errorString())
            << endl;
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;


    if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        cerr << "Error: parse error at line " << errorLine << " , "
            << "column " << errorColumn << " : "
            << qPrintable(errorStr) << endl;
        return false;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "phy_teds")
    {
        cerr << "Error : Not a valid phy teds file" << endl;
        return false;
    }
    parsePhyTeds(root);

    // cout << root. << endl;
    return true;
}


bool DomParser::readTransducerTedsFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        cerr << "Error: Cannot reaf file" << qPrintable(filename)
            << ": "  << qPrintable(file.errorString())
            << endl;
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;


    if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        cerr << "Error: parse error at line " << errorLine << " , "
            << "column " << errorColumn << " : "
            << qPrintable(errorStr) << endl;
        return false;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "transducerchannel_teds")
    {
        cerr << "Error : Not a valid transducer teds file" << endl;
        return false;
    }
    parseTransducerTeds(root);

    // cout << root. << endl;
    return true;
}


void DomParser::parseMetaTeds(const QDomElement &element)
{
    QDomNode child = element.firstChild();

    while (!child.isNull())
    {
        if (child.toElement().tagName() == "length")
        {
              //cout << "length: " << child.toElement().text().toLatin1().data() << endl;
              meta->length = child.toElement().text().toUShort();
              cout << "length: " << meta->length << endl;
        }
        else if (child.toElement().tagName() == "identifier")
        {
            //  cout << "indetifier: " << child.toElement().text().toLatin1().data() << endl;
              meta->identifier = (unsigned char) child.toElement().text().toInt();
              cout << "identifier: " << (int)meta->identifier << endl;

        }
        else if (child.toElement().tagName() == "family")
        {
              //cout << "family: " << child.toElement().text().toLatin1().data() << endl;
              meta->family = (unsigned char) child.toElement().text().toInt();
              cout << "family: " << (int)meta->family << endl;

        }
        else if (child.toElement().tagName() == "version")
        {
              //cout << "version: " << child.toElement().text().toLatin1().data() << endl;
              meta->version = (unsigned char) child.toElement().text().toInt();
              cout << "version: " << (int)meta->version << endl;

        }
        else if (child.toElement().tagName() == "TEDS_hold-off_time")
        {
              //cout << "TEDS hold-off time: " << child.toElement().text().toLatin1().data() << endl;
              meta->teds_hold_off_time = child.toElement().text().toFloat();
              cout << "TEDS hold-off time: " << meta->teds_hold_off_time << endl;
        }
        else if (child.toElement().tagName() == "Operational_hold-off_time")
        {
              //cout << "Operational hold-off time: " << child.toElement().text().toLatin1().data() << endl;
              meta->operation_hold_off_time = child.toElement().text().toFloat();
              cout << "Operational hold-off time: " << meta->operation_hold_off_time << endl;
        }
        else if (child.toElement().tagName() == "Maximun_sustained_load_current_drawn_from_the_transducer_bus")
        {
              //cout << "Maximun sustained load current drawn from the transducer bus: " << child.toElement().text().toLatin1().data() << endl;
              meta->sustained_load_current = child.toElement().text().toFloat();
              cout << "Maximun sustained load current drawn from the transducer bus: " << meta->sustained_load_current << endl;
        }
        else if (child.toElement().tagName() == "Multirange_capability")
        {
              //cout << "Multirange capability: " << child.toElement().text().toLatin1().data() << endl;
              meta->multirange_capability = (unsigned int)child.toElement().text().toInt();
              cout << "Multirange capability: " << (int)meta->multirange_capability << endl;
        }
        else if (child.toElement().tagName() == "Number_of_ControlGroups")
        {
              //cout << "Number of ControlGroups: " << child.toElement().text().toLatin1().data() << endl;
              meta->number_of_controlgroup = (unsigned int)child.toElement().text().toInt();
              cout << "Number of ControlGroups: " << (int)meta->number_of_controlgroup << endl;

        }
        else if (child.toElement().tagName() == "ControlGroup_type")
        {
              //cout << "<ControlGroup type: " << child.toElement().text().toLatin1().data() << endl;
              meta->controlgroup_type = (unsigned int)child.toElement().text().toInt();
              cout << "<ControlGroup type: " << (int)meta->controlgroup_type << endl;
        }
        else if (child.toElement().tagName() == "Number_of_TransducerChannels_in_the_ControlGroup")
        {
              //cout << "Number of TransducerChannels in the ControlGroup: " << child.toElement().text().toLatin1().data() << endl;
              meta->num_of_ts_in_contrlgroup = (unsigned int)child.toElement().text().toInt();
              cout << "Number of TransducerChannels in the ControlGroup: " << (int) meta->num_of_ts_in_contrlgroup << endl;
        }
        else if (child.toElement().tagName() == "ControlGroup_member_list")
        {
              //cout << "ControlGroup member list: " << child.toElement().text().toLatin1().data() << endl;
              meta->controlgroup_list = (unsigned int) child.toElement().text().toInt();
              cout << "ControlGroup member list: " << (int)meta->controlgroup_list << endl;

        }
        else if (child.toElement().tagName() == "Number_of_VectorGroups")
        {
              //cout << "Number of VectorGroups: " << child.toElement().text().toLatin1().data() << endl;
              meta->number_of_vectorgroups = (unsigned int) child.toElement().text().toInt();
              cout << "Number of VectorGroups: " << (int)meta->number_of_vectorgroups << endl;

        }
        else if (child.toElement().tagName() == "VectorGroup_type")
        {
              //cout << "VectorGroup type: " << child.toElement().text().toLatin1().data() << endl;
              meta->vectorgroup_type = (unsigned int) child.toElement().text().toInt();
              cout << "VectorGroup type: " << (int)meta->vectorgroup_type << endl;
        }
        else if (child.toElement().tagName() == "Number_of_TransducerChannels_in_the_VectorGroup")
        {
              //cout << "Number of TransducerChannels in the VectorGroup: " << child.toElement().text().toLatin1().data() << endl;
              meta->num_of_ts_in_vectorgroup = (unsigned int) child.toElement().text().toInt();
              cout << "Number of TransducerChannels in the VectorGroup: " << (int)meta->num_of_ts_in_vectorgroup << endl;
        }
        else if (child.toElement().tagName() == "VectorGroup_member_list")
        {
              //cout << "VectorGroup member list: " << child.toElement().text().toLatin1().data() << endl;
              meta->vectorgroup_list = (unsigned int) child.toElement().text().toInt();
              cout << "Number of TransducerChannels in the VectorGroup: " << (int)meta->vectorgroup_list << endl;
        }
        else if (child.toElement().tagName() == "Number_of_TransducerChannel_proxies")
        {
              //cout << "Number of TransducerChannel proxies: " << child.toElement().text().toLatin1().data() << endl;
              meta->num_of_ts_proxy = (unsigned int) child.toElement().text().toInt();
              cout << "Number of TransducerChannel proxies: " << (int)meta->num_of_ts_proxy << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_number_of_the_TransducerChannel_proxy")
        {
              //cout << "TransducerChannel number of the TransducerChannel proxy: " << child.toElement().text().toLatin1().data() << endl;
              meta->ts_num_of_ts_proxy = (unsigned int) child.toElement().text().toInt();
              cout << "TransducerChannel number of the TransducerChannel proxy: " << (int)meta->ts_num_of_ts_proxy << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_proxy_data_set_organization")
        {
              //cout << "TransducerChannel proxy data set organization: " << child.toElement().text().toLatin1().data() << endl;
              meta->ts_proxy_data_set_organization = (unsigned int) child.toElement().text().toInt();
              cout << "TransducerChannel number of the TransducerChannel proxy: " << (int)meta->ts_proxy_data_set_organization << endl;
        }
        else if (child.toElement().tagName() == "Number_of_TransducerChannels_represented_by_this_proxy")
        {
              //cout << "Number of TransducerChannels represented by this proxy: " << child.toElement().text().toLatin1().data() << endl;
              meta->ts_num_of_proxy = (unsigned int) child.toElement().text().toInt();
              cout << "Number of TransducerChannels represented by this proxy: " << (int)meta->ts_num_of_proxy << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_proxy_member_list")
        {
              //cout << "TransducerChannel proxy member list: " << child.toElement().text().toLatin1().data() << endl;
              meta->ts__proxy_teds = (unsigned int) child.toElement().text().toInt();
              cout << "TransducerChannel proxy member list: " << (int)meta->ts__proxy_teds << endl;
        }
        else if (child.toElement().tagName() == "checksum")
        {
              //cout << "checksum: " << child.toElement().text().toLatin1().data() << endl;
              meta->checksum = (unsigned int) child.toElement().text().toInt();
              cout << "check : " << (int)meta->checksum << endl;
        }



        child = child .nextSibling();
    }
    char * str = (char *) malloc(sizeof(Meta_TEDS) + 2);
    char * s = str;
    *s = (char)0X5A;
    s ++;

    char * m = (char *) meta;
    cout << "size meta: " << sizeof(Meta_TEDS) << endl;
    for(int i = 0; i < sizeof(Meta_TEDS); i ++)
    {
        //cout << *str<<" " ;
        *s = *m;
        cout << (int)*m << " " ;
        s ++;
        m ++;
    }
    *s = (char) 0XA5;
    cout << "str = " << *str << endl;
    for (int i = 0; i < sizeof(Meta_TEDS) + 2; i ++)
    {
        cout << (int)str[i] << " ";
    }
    cout << endl;
    QString strTemp = "";
    for (int i = 0; i < sizeof(Meta_TEDS) + 2; i ++)
    {
        strTemp += str[i];
    }
    strMeta = strTemp;
}

void DomParser::parsePhyTeds(const QDomElement &element)
{
    QDomNode child = element.firstChild();

    while (!child.isNull())
    {
        if (child.toElement().tagName() == "length")
        {
              //cout << "length: " << child.toElement().text().toLatin1().data() << endl;
              phy->length = child.toElement().text().toUShort();
              cout << "length: " << phy->length << endl;
        }
        else if (child.toElement().tagName() == "identifier")
        {
            //  cout << "indetifier: " << child.toElement().text().toLatin1().data() << endl;
              phy->identifier = (unsigned char) child.toElement().text().toInt();
              cout << "identifier: " << (int)phy->identifier << endl;

        }
        else if (child.toElement().tagName() == "asynchronous-only_flag")
        {
              //cout << "asynchronous-only_flag: " << child.toElement().text().toLatin1().data() << endl;
              phy->asynchronous_only_flag = (unsigned char) child.toElement().text().toInt();
              cout << "asynchronous-only_flag: " << (int)phy->asynchronous_only_flag << endl;

        }
        else if (child.toElement().tagName() == "highest_supported_payload_encoding")
        {
              //cout << "highest_supported_payload_encoding: " << child.toElement().text().toLatin1().data() << endl;
              phy->highest_supported_payload_encoding = (unsigned char) child.toElement().text().toInt();
              cout << "highest_supported_payload_encoding: " << (int)phy->highest_supported_payload_encoding << endl;

        }
        else if (child.toElement().tagName() == "start_delay")
        {
              //cout << "start_delay: " << child.toElement().text().toLatin1().data() << endl;
              phy->start_delay = child.toElement().text().toFloat();
              cout << "start_delay: " << phy->start_delay << endl;
        }
        else if (child.toElement().tagName() == "reflect_delay")
        {
              //cout << "reflect_delay: " << child.toElement().text().toLatin1().data() << endl;
              phy->reflect_delay = child.toElement().text().toFloat();
              cout << "reflect_delay: " << phy->reflect_delay << endl;
        }
        else if (child.toElement().tagName() == "reflect_delay_uncertainty")
        {
              //cout << "reflect_delay_uncertainty: " << child.toElement().text().toLatin1().data() << endl;
              phy->reflect_delay_uncertainty = child.toElement().text().toFloat();
              cout << "reflect_delay_uncertainty: " << phy->reflect_delay_uncertainty << endl;
        }
        else if (child.toElement().tagName() == "checksum")
        {
              //cout << "checksum: " << child.toElement().text().toLatin1().data() << endl;
              meta->checksum = (unsigned short) child.toElement().text().toInt();
              cout << "check : " << (int)meta->checksum << endl;
        }



        child = child .nextSibling();
    }
    char * str = (char *) malloc(sizeof(Phy_TEDS) + 2);
    char * s = str;
    *s = (char)0X5A;
    s ++;
    char * m = (char *) phy;
    cout << "size phy: " << sizeof(Phy_TEDS) << endl;
    for(int i = 0; i < sizeof(Phy_TEDS); i ++)
    {
        //cout << *str<<" " ;
        *s = *m;
        cout << (int)*m << " " ;
        s ++;
        m ++;
    }
    *s = (char)0XA5;
    cout << "str = " << *str << endl;
    char * ss = str;
    for (int i = 0; i < sizeof(Phy_TEDS) + 2; i ++)
    {
        cout << (int)str[i] << " ";
    }
    cout << endl;
    QString strTemp = "";
    for (int i = 0; i < sizeof(Phy_TEDS) + 2; i ++)
    {
        strTemp += str[i];
    }
    strPhy = strTemp;

}


void DomParser::parseTransducerTeds(const QDomElement &element)
{
    QDomNode child = element.firstChild();

    while (!child.isNull())
    {
        if (child.toElement().tagName() == "length")
        {
              //cout << "length: " << child.toElement().text().toLatin1().data() << endl;
              ts->length = child.toElement().text().toUShort();
              cout << "length: " << ts->length << endl;
        }
        else if (child.toElement().tagName() == "identifier")
        {
            //  cout << "indetifier: " << child.toElement().text().toLatin1().data() << endl;
              ts->identifier = (unsigned char) child.toElement().text().toInt();
              cout << "identifier: " << (int)ts->identifier << endl;

        }
        else if (child.toElement().tagName() == "Calibration_key")
        {
              //cout << "Calibration_key: " << child.toElement().text().toLatin1().data() << endl;
              ts->calibration_key = (unsigned char) child.toElement().text().toInt();
              cout << "Calibration_key: " << (int)ts->calibration_key << endl;

        }
        else if (child.toElement().tagName() == "TransducerChannel_type_key")
        {
              //cout << "TransducerChannel_type_key: " << child.toElement().text().toLatin1().data() << endl;
              ts->ts_type_key = (unsigned char) child.toElement().text().toInt();
              cout << "TransducerChannel_type_key: " << (int)ts->ts_type_key << endl;

        }
        else if (child.toElement().tagName() == "Physical_units")
        {
              //cout << "Physical_units: " << child.toElement().text().toLatin1().data() << endl;
              ts->physical_units = (unsigned char)child.toElement().text().toInt();
              cout << "Physical_units: " << (int)ts->physical_units << endl;
        }
        else if (child.toElement().tagName() == "Design_operational_lower_range_limit")
        {
              //cout << "Design_operational_lower_range_limit: " << child.toElement().text().toLatin1().data() << endl;
              ts->op_lower_range_limit = child.toElement().text().toFloat();
              cout << "Design_operational_lower_range_limit: " << ts->op_lower_range_limit << endl;
        }
        else if (child.toElement().tagName() == "Design_operational_upper_range_limit")
        {
              //cout << "Design_operational_upper_range_limit: " << child.toElement().text().toLatin1().data() << endl;
              ts->op_upper_range_limit = child.toElement().text().toFloat();
              cout << "Design_operational_upper_range_limit: " << ts->op_upper_range_limit << endl;
        }
        else if (child.toElement().tagName() == "Uncertainty_under_worst-case_conditions")
        {
              //cout << "Uncertainty_under_worst-case_conditions: " << child.toElement().text().toLatin1().data() << endl;
              ts->worst_uncertainty = child.toElement().text().toFloat();
              cout << "Uncertainty_under_worst-case_conditions: " << ts->worst_uncertainty << endl;
        }
        else if (child.toElement().tagName() == "Self-test_key")
        {
              //cout << "Self-test_key: " << child.toElement().text().toLatin1().data() << endl;
              ts->self_test = (unsigned char) child.toElement().text().toInt();
              cout << "Self-test_key: " << (int)ts->self_test << endl;
        }
        else if (child.toElement().tagName() == "Data_model")
        {
              //cout << "Data_model: " << child.toElement().text().toLatin1().data() << endl;
              ts->data_model = (unsigned char) child.toElement().text().toInt();
              cout << "Data_model: " << (int)ts->data_model << endl;
        }
        else if (child.toElement().tagName() == "Data_model_length")
        {
              //cout << "Data_model_length: " << child.toElement().text().toLatin1().data() << endl;
              ts->data_model_len = (unsigned char) child.toElement().text().toInt();
              cout << "Data_model_length: " << (int)ts->data_model_len << endl;
        }
        else if (child.toElement().tagName() == "Model_significant_bits")
        {
              //cout << "Model_significant_bits: " << child.toElement().text().toLatin1().data() << endl;
              ts->model_significant_bit = (unsigned short) child.toElement().text().toInt();
              cout << "Model_significant_bits: " << ts->model_significant_bit << endl;
        }
        else if (child.toElement().tagName() == "Maximum_data_repetitions")
        {
              //cout << "Maximum_data_repetitions: " << child.toElement().text().toLatin1().data() << endl;
              ts->max_data_repetition = (unsigned short) child.toElement().text().toInt();
              cout << "Maximum_data_repetitions: " << ts->max_data_repetition << endl;
        }
        else if (child.toElement().tagName() == "Series_origin")
        {
              //cout << "Series_origin: " << child.toElement().text().toLatin1().data() << endl;
              ts->series_origin = child.toElement().text().toFloat();
              cout << "Series_origin: " << ts->series_origin << endl;
        }
        else if (child.toElement().tagName() == "Series_increment")
        {
              //cout << "Series_increment: " << child.toElement().text().toLatin1().data() << endl;
              ts->series_increment = child.toElement().text().toFloat();
              cout << "Series_increment: " << ts->series_increment << endl;
        }
        else if (child.toElement().tagName() == "Series_units")
        {
              //cout << "Series_units: " << child.toElement().text().toLatin1().data() << endl;
              ts->physical_units = (unsigned char) child.toElement().text().toFloat();
              cout << "Series_units: " << (int)ts->physical_units << endl;
        }
        else if (child.toElement().tagName() == "Maximum_pre-trigger_samples")
        {
              //cout << "Maximum_pre-trigger_samples: " << child.toElement().text().toLatin1().data() << endl;
              ts->max_pre_trigger_samp = (unsigned short) child.toElement().text().toFloat();
              cout << "Maximum_pre-trigger_samples: " << ts->max_pre_trigger_samp << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_update_time")
        {
              //cout << "TransducerChannel_update_time: " << child.toElement().text().toLatin1().data() << endl;
              ts->ts_update_time = child.toElement().text().toFloat();
              cout << "TransducerChannel_update_time: " << ts->ts_update_time << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_write_setup_time")
        {
              //cout << "TransducerChannel_write_setup_time: " << child.toElement().text().toLatin1().data() << endl;
              ts->ts_write_setup_time = child.toElement().text().toFloat();
              cout << "TransducerChannel_write_setup_time: " << ts->ts_write_setup_time << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_read_setup_time")
        {
              //cout << "TransducerChannel_read_setup_time: " << child.toElement().text().toLatin1().data() << endl;
              ts->ts_read_setup_time = child.toElement().text().toFloat();
              cout << "TransducerChannel_read_setup_time: " << ts->ts_read_setup_time << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_sampling_period")
        {
              //cout << "TransducerChannel_sampling_period: " << child.toElement().text().toLatin1().data() << endl;
              ts->ts_sampling_period = child.toElement().text().toFloat();
              cout << "TransducerChannel_sampling_period: " << ts->ts_sampling_period << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_warm-up_time")
        {
              //cout << "TransducerChannel_warm-up_time: " << child.toElement().text().toLatin1().data() << endl;
              ts->ts_wram_up_time = child.toElement().text().toFloat();
              cout << "TransducerChannel_warm-up_time: " << ts->ts_wram_up_time << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_read_delay_time")
        {
              //cout << "TransducerChannel_read_delay_time: " << child.toElement().text().toLatin1().data() << endl;
              ts->ts_read_delay = child.toElement().text().toFloat();
              cout << "TransducerChannel_read_delay_time: " << ts->ts_read_delay << endl;
        }
        else if (child.toElement().tagName() == "TransducerChannel_self-test_time_requirement")
        {
              //cout << "TransducerChannel_self-test_time_requirement: " << child.toElement().text().toLatin1().data() << endl;
              ts->sef_test_time = child.toElement().text().toFloat();
              cout << "TransducerChannel_self-test_time_requirement: " << ts->sef_test_time << endl;
        }
        else if (child.toElement().tagName() == "Source_for_the_time_of_sample")
        {
              //cout << "Source_for_the_time_of_sample: " << child.toElement().text().toLatin1().data() << endl;
              ts->source_time = (unsigned char) child.toElement().text().toInt();
              cout << "Source_for_the_time_of_sample: " << (int)ts->source_time << endl;
        }
        else if (child.toElement().tagName() == "Incoming_propagation_delay_through_the_data_transport_logic")
        {
              //cout << "Incoming_propagation_delay_through_the_data_transport_logic: " << child.toElement().text().toLatin1().data() << endl;
              ts->income_propagation_delay = child.toElement().text().toFloat();
              cout << "Incoming_propagation_delay_through_the_data_transport_logic: " << ts->income_propagation_delay << endl;
        }
        else if (child.toElement().tagName() == "Outgoing_propagation_delay_through_the_data_transport_logic")
        {
              //cout << "Outgoing_propagation_delay_through_the_data_transport_logic: " << child.toElement().text().toLatin1().data() << endl;
              ts->outgoing_propagation_delay = child.toElement().text().toFloat();
              cout << "Outgoing_propagation_delay_through_the_data_transport_logic: " << ts->outgoing_propagation_delay << endl;
        }
        else if (child.toElement().tagName() == "Trigger-to-sample_delay_uncertainty")
        {
              //cout << "Trigger-to-sample_delay_uncertainty: " << child.toElement().text().toLatin1().data() << endl;
              ts->triggertosample_delay = (unsigned short) child.toElement().text().toFloat();
              cout << "Trigger-to-sample_delay_uncertainty: " << ts->triggertosample_delay << endl;
        }
        else if (child.toElement().tagName() == "Sampling_attribute")
        {
              //cout << "Sampling_attribute: " << child.toElement().text().toLatin1().data() << endl;
              ts->sample_attribute = (unsigned short) child.toElement().text().toInt();
              cout << "Sampling_attribute: " << (int)ts->sample_attribute << endl;
        }
        else if (child.toElement().tagName() == "Buffered_attribute")
        {
              //cout << "Buffered_attribute: " << child.toElement().text().toLatin1().data() << endl;
              ts->buffered_attribute = (unsigned short) child.toElement().text().toInt();
              cout << "Buffered_attribute: " << (int)ts->buffered_attribute << endl;
        }
        else if (child.toElement().tagName() == "End-of-data-set_operation_attribute")
        {
              //cout << "End-of-data-set_operation_attribute: " << child.toElement().text().toLatin1().data() << endl;
              ts->end_data_set_op_attr = (unsigned short) child.toElement().text().toInt();
              cout << "End-of-data-set_operation_attribute: " << (int)ts->edge_to_report_attr << endl;
        }
        else if (child.toElement().tagName() == "Streaming_attribute")
        {
              //cout << "Streaming_attribute: " << child.toElement().text().toLatin1().data() << endl;
              ts->streaming_attribute = (unsigned short) child.toElement().text().toInt();
              cout << "Streaming_attribute: " << (int)ts->streaming_attribute << endl;
        }
        else if (child.toElement().tagName() == "Edge-to-report_attribute")
        {
              //cout << "Edge-to-report_attribute: " << child.toElement().text().toLatin1().data() << endl;
              ts->edge_to_report_attr = (unsigned short) child.toElement().text().toInt();
              cout << "Edge-to-report_attribute: " << (int)ts->edge_to_report_attr << endl;
        }
        else if (child.toElement().tagName() == "Actuator-halt_attribute")
        {
              //cout << "Actuator-halt_attribute: " << child.toElement().text().toLatin1().data() << endl;
              ts->actuator_halt_attr = (unsigned short) child.toElement().text().toInt();
              cout << "Actuator-halt_attribute: " << (int)ts->actuator_halt_attr << endl;
        }
        else if (child.toElement().tagName() == "Sensitivity_direction")
        {
              //cout << "Sensitivity_direction: " << child.toElement().text().toLatin1().data() << endl;
              ts->sensitivity_direction = (unsigned short) child.toElement().text().toInt();
              cout << "Sensitivity_direction: " << (int)ts->sensitivity_direction << endl;
        }
        else if (child.toElement().tagName() == "Direction_angles")
        {
              //cout << "Direction_angles: " << child.toElement().text().toLatin1().data() << endl;
              ts->direction_angles = child.toElement().text().toFloat();
              cout << "Direction_angles: " << ts->direction_angles << endl;
        }
        else if (child.toElement().tagName() == "Event_sensor_options")
        {
              //cout << "Event_sensor_options: " << child.toElement().text().toLatin1().data() << endl;
              ts->event_sensor_op = (unsigned char) child.toElement().text().toInt();
              cout << "Event_sensor_options: " << (int)ts->event_sensor_op << endl;
        }
        else if (child.toElement().tagName() == "checksum")
        {
              //cout << "checksum: " << child.toElement().text().toLatin1().data() << endl;
              ts->checksum = (unsigned short) child.toElement().text().toInt();
              cout << "check : " << (int)meta->checksum << endl;
        }



        child = child .nextSibling();
    }
    char * str = (char *) malloc(sizeof(Transducerchannel_TEDS));
    char * s = str;
    *s = (char)0X5A;
    s ++;
    char * m = (char *) ts;
    cout << "size tansducer: " << sizeof(Transducerchannel_TEDS) << endl;
    for(int i = 0; i < sizeof(Transducerchannel_TEDS); i ++)
    {
        //cout << *str<<" " ;
        *s = *m;
        cout << (int)*m << " " ;
        s ++;
        m ++;
    }
    *s = (char)0XA5;
    cout << "str = " << *str << endl;

    for (int i = 0; i < sizeof(Transducerchannel_TEDS) + 2; i ++)
    {
        cout << (int)str[i] << " ";
    }
    cout << endl;

    QString strTemp = "";
    for (int i = 0; i < sizeof(Transducerchannel_TEDS) + 2; i ++)
    {
        strTemp += str[i];
    }
    strTs = strTemp;
 /*   for (int i = 0; i < sizeof(Transducerchannel_TEDS) + 2; i ++)
        cout << (int)strTemp.toLatin1().constData()[i] << ", ";
    cout << endl;
 */
}


