#!/usr/bin/python3

import xml.etree.ElementTree as ET

# Load the GoogleTest XML output
gtest_tree = ET.parse('test_results.xml')
gtest_root = gtest_tree.getroot()

# Create a root element for JUnit XML
junit_testsuites = ET.Element('testsuites')

# Iterate through each GoogleTest testsuite
for gtest_testsuite in gtest_root.findall('testsuite'):
    # Create a corresponding JUnit testsuite element
    junit_testsuite = ET.SubElement(junit_testsuites, 'testsuite', 
                                    name=gtest_testsuite.get('name'),
                                    tests=gtest_testsuite.get('tests'),
                                    failures=gtest_testsuite.get('failures'))
    
    # Iterate through the test cases
    for gtest_testcase in gtest_testsuite.findall('testcase'):
        # Create a corresponding JUnit testcase element
        junit_testcase = ET.SubElement(junit_testsuite, 'testcase',
                                       classname=gtest_testsuite.get('name'),
                                       name=gtest_testcase.get('name'),
                                       time=gtest_testcase.get('time'))
        
        # Check if the test case has failures
        failure = gtest_testcase.find('failure')
        if failure is not None:
            junit_failure = ET.SubElement(junit_testcase, 'failure', 
                                          message=failure.get('message'))
            junit_failure.text = failure.text

# Write the JUnit XML to a file
junit_tree = ET.ElementTree(junit_testsuites)
junit_tree.write('junit_output.xml', encoding='UTF-8', xml_declaration=True)