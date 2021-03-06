/**
 * Copyright (C) 2013 TomTom International B.V.
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
package org.genivi.trafficincidentsservice.trafficincidents.dbus;

import org.freedesktop.dbus.Position;
import org.freedesktop.dbus.Struct;

public class LaneRestrictionsStruct extends Struct {
  @Position(0)
  public final Byte laneRestrictionType;   // LaneRestrictionType
  
  @Position(1)
  public final Integer numberOfLanes;

  public LaneRestrictionsStruct(Byte laneRestrictionType, int numberOfLanes) {
    super();
    this.laneRestrictionType = laneRestrictionType;
    this.numberOfLanes = numberOfLanes;
  }
}
