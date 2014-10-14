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

package modules.nodes;

import modules.mobility.models.CustomRectangleMobility;
import modules.mobility.models.CustomLinearMobility;
import modules.nodes.MyWirelessNode;


module HostBici extends MyWirelessNode
{
    parameters:

        mobilityType = default("CustomLinearMobility");
        
        
        //Parametros de la bateria
        batteryStats.detail = default(false);
        batteryStats.timeSeries = default(false);

        battery.nominal = default(1000 mAh);
        battery.capacity = default(battery.nominal);
        battery.voltage = default(3 V);
        battery.resolution = default(60 s);
        battery.publishDelta = default(1);
        battery.publishTime = default(battery.resolution);
        battery.numDevices = default(1);


        //Señal para indicar el envío de un paquete
        @signal[sent](type="int");
        @statistic[sentPackages](title="sent package"; source="sent"; record=vector,stats; interpolationmode=none);

        //Señal para indicar la recepción de un paquete
        @signal[received](type="int");
        @statistic[receivedPackages](title="received package"; source="received"; record=vector,stats; interpolationmode=none);

        //Señal para indicar la posición x cuando se recibe un paquete
        @signal[xposition](type="double");
        @statistic[xPosition](title="position x"; source="xposition"; record=vector,stats; interpolationmode=none);

        //Señal para indicar la posición y cuando se recibe un paquete
        @signal[yposition](type="double");
        @statistic[yPosition](title="position y"; source="yposition"; record=vector,stats; interpolationmode=none);

        //Señal para indicar la recepción de un paquete broadcast
        @signal[received_broadcast](type="int");
        @statistic[received_broadcast](title="received broadcast"; source="received_broadcast"; record=vector,stats; interpolationmode=none);

        //Señal para indicar el tiempo de llegada del nodo a la meta
        @signal[arrival_time](type="double");
        @statistic[arrival_time](title="arrival time"; source="arrival_time"; record=last);

        //Se�al para indicar la aceleraci�n que se aplica al nodo
        @signal[accelerationPlatoon](type="double");
        @statistic[accelerationPlatoon](title="acceleration platoon"; source="accelerationPlatoon"; record=vector,stats; interpolationmode=none);

        //Se�al para indicar la distancia al nodo del frente
        @signal[distanceToFwd](type="double");
        @statistic[distanceToFwd](title="distance to fwd"; source="distanceToFwd"; record=vector,stats; interpolationmode=none);

}
