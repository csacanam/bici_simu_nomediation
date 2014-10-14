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

#ifndef CUSTOMAPPLAYER_H_
#define CUSTOMAPPLAYER_H_

#include "MiXiMDefs.h"
#include <MyTestAppLayer.h>
#include <NodeInfo.h>

class MIXIM_API CustomAppLayer: public MyTestAppLayer {
private:
    //Cantidad de paquetes enviados
    long numSent;
    //Cantidad de paquetes recibidos
    long numReceived;
    //ID consecutivo del paquete
    int packageID;
    //Cantidad de paquetes broadcast recibidos
    long numReceivedBroadcast;

    //Distancia total entre el inicio y la meta
    double totalDistance;

    //Bandera para determinar si hay o no comunicacion
    bool comEnabled;
    //Indicadores de llegada a la meta
    bool llegada;
    double finalSpeed;
    double finalAcceleration;

    //Message to schedule next platoon update
    cMessage* timeToPlatoonInfo;

    std::vector<NodeInfo*> nodeInfoVector;

    //Se朼l para emitir la aceleraci梟 aplicada
    simsignal_t accelerationPlatoonSignal;

    //Se朼l para emitir la distancia del nodo actual al nodo frontal
    simsignal_t distanceToFwdSignal;

    //Se帽al para emitir tiempo de llegada del nodo a la meta
    simsignal_t arrivalTimeSignal;

    //Se帽al para emitir cuando se env铆a un paquete
    simsignal_t sentSignal;

    //Se帽al para emitir cuando se recibe un paquete
    simsignal_t receivedSignal;

    //Se帽al para emitir la posici贸n x del m贸dulo cuando se recibe un paquete
    simsignal_t positionXSignal;

    //Se帽al para emitir la posici贸n y del m贸dulo cuando se recibe un paquete
    simsignal_t positionYSignal;

    //Se帽al para emitir cuando se recibe un paquete broadcast
    simsignal_t receivedBroadcastSignal;

    //Aceleracion del ultimo platoon
    double lastAccelerationPlatoon;

    //Alpha values of CACC
    double alpha1;
    double alpha2;
    double alpha3;
    double alpha4;
    double alpha5;

    //Alpha values of CACC with lag
    double alphaLag;

    //Values for calculating Spacing Error
    double length_vehicle_front;
    double desiredSpacing;

    //Position update interval
    double beaconInterval;

    //Platoon update interval
    double platoonInterval;



public:
    CustomAppLayer() :
        MyTestAppLayer(),burstSize(0),bSendReply(true)
    {

    }
    virtual ~CustomAppLayer();

    /** @brief Initialize module parameters*/
    virtual void initialize(int);

protected:
    /** @brief Handle self messages such as timer... */
    virtual void handleSelfMsg(cMessage*);

    /** @brief Handle messages from lower layer */
    virtual void handleLowerMsg(cMessage*);

    /** @brief Permite obtener la posici贸n x del m贸dulo */
    virtual double getModuleXPosition();

    /** @brief Permite obtener la posici贸n y del m贸dulo */
    virtual double getModuleYPosition();

    /** @brief Permite obtener la velocidad del m贸dulo */
    virtual double getModuleSpeed();

    /** @brief Permite obtener la aceleraci贸n del m贸dulo */
    virtual double getModuleAcceleration();

    /** @brief Permite actualizar el tag del m贸dulo donde se muestran los datos*/
    virtual void updateDisplay();

    /** @brief Permite determinar la distancia entre dos nodos dadas sus posiciones x e y y la zon en la cual est锟絥*/
    virtual double getDistanceBetweenNodes(double posx_1, double posy_1, int zona_1, double posx_2, double posy_2, int zona_2);

    /** @brief Permite determinar la distancia entre dos nodos dadas sus posiciones x**/
    virtual double getDistanceBetweenNodes2(double posx_1,double posx_2);

    /** @brief Permite obtener la distancia del nodo al punto de referencia (0,800)*/
    virtual double getAbsoluteDistance(double posx, double posy, int zona);

    /** @brief Permite modificar la aceleracion de un nodo */
    virtual void setAcceleration(double acceleration);



    /** @brief Number of messages to send in a burst*/
    int burstSize;
    /** @brief If true, send a unicast BROADCAST_REPLY message to each
     * received BROADCAST message. */
    bool bSendReply;
};

#endif /* CUSTOMAPPLAYER_H_ */
