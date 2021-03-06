//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package modules.application;

import org.mixim.base.modules.IBaseApplLayer;

simple CustomAppLayer like IBaseApplLayer
{
    parameters:
        double totalDistance @unit(m);//Distancia total desde el inicio hasta la meta
        bool coreDebug = default(false); //debug switch for base class (TestApplLayer)
    	bool debug      = default(false); // debug switch
    	int headerLength @unit("bit"); // length of the application message header (in bits)
    	int burstSize; // size of the burst
    	bool burstReply = default(false);  // if true, send unicast replies to received broadcasts
    	
    	//Alpha values of CACC
    	double alpha1;
    	double alpha2;
    	double alpha3;
    	double alpha4;
    	double alpha5;
    	
    	//Alpha values of CACC with lag
    	double alphaLag;
    	
    	//Values for spacing error
    	double spacing;
    	double lenghtVehicle;
    	
    	//Update interval for beacons (position update)
    	double beaconInterval @unit(s);
    	
    	//Update interval for platoon
    	double platoonInterval @unit(s);
    	
    gates:
    	input lowerLayerIn; // from network layer
        output lowerLayerOut; // to network layer
        input lowerControlIn; // control from network layer
        output lowerControlOut; // control to network layer
}