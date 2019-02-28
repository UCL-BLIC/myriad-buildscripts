/*
 * flowData.hpp
 *
 *  Created on: Apr 13, 2012
 *      Author: wjiang2
 */

#ifndef FLOWDATA_HPP_
#define FLOWDATA_HPP_
#include <vector>
#include <iostream>
#include <string>
#include <valarray>
#include <stdexcept>

using namespace std;

#include <boost/config.hpp>
#include <boost/graph/adj_list_serialize.hpp>
#include <boost/algorithm/string.hpp>
#include "global.hpp"
unsigned find_pos(vector<string> s,string pattern, bool ignore_case);
/*
 * representing one FCS data
 * currently used as a transient copy of flow data (passed from R)
 * resource is released once the gating is done
 */
class flowData{

public:
	vector<string> params;
	unsigned sampleID;//it is only valid when access cdf version of flowdata, used as index for sample dimension
	valarray<double> data;
	unsigned nEvents;
	bool ignore_case; //whether channel-searching is case sensitive


	flowData & operator=(const flowData& source);//explicitly define the copy assignment since the default one is compiler-specific
	flowData();
	flowData(double* mat,vector<string>,unsigned _nEvents,unsigned _sampleID, bool _ignore_case = false);
	slice getSlice(string channel) const;
	void updateSlice(string channel,valarray<double> x);
	valarray<double> subset(string channel) const;
	/*
	 * accessors
	 */
	void setParams(vector<string> _params);
	vector<string> getParams(){return params;};
	void setEventCount(unsigned _nEvents){nEvents=_nEvents;};
	unsigned getEventsCount(){return nEvents;};
	void setSampleID(unsigned _sampleID){sampleID=_sampleID;};
	unsigned getSampleID(){return sampleID;};

	void clear(){data.resize(0);};
	unsigned dataSize(){return data.size();};
	void getData(double * mat,unsigned nSize);
	valarray<double> getData();
};




#endif /* FLOWDATA_HPP_ */
