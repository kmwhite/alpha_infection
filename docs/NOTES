Components:
  Combat:
    How characters fight each other, probes, or the Alpha Infection itself
      * CHARACTERS
        - CHARACTER has 100HP
        - CHARACTER being ATTACKED activates TWO shields.
        - CHARACTER doing ATTACK attacks spot on TARGET
        - If HIT
          - If TARGET contains a weapon at that location, it is DESTROYED
            - Player loses the ability to use that WEAPON
            - Player must find the WEAPON in a new location
            - Player is delated from combating the AI
          - If TARGET contains nothing at that location, DAMAGE is given
            - FIXME_DEFINE_DAMAGE_CALCULATION_ALGORITHM
        - If MISS
          - ATTACK is over
      * PROBES
        - PROBE has 75HP
        - PROBE being ATTACKED activates TWO shields
        - Player doing ATTACK attacks a spot on PROBE
        - If HIT
	  - FIXME_DEFINE_DAMAGE_CALCULATION_ALGORITHM
      * AlphaInfection (AI)
        - ATTACKER
        - ATTACKEE
  Cartography:
    Where the individual pickups and consumables are located:
      * 3x Weapons that have MODIFIER behaviors on Player experience
        - WEAPON_LOC_TOP, found in a ROOM_CLASS_1 map location
            MODIFIER: Allows you to listen to the SECRET CODE conversations
            between AI and other Players.
        - WEAPON_LOC_LEFT, found in a ROOM_CLASS_2 map location
            MODIFIER: Add an additional sheld when in combat
        - WEAPON_LOC_RIGHT, found in a ROOM_CLASS_3 map location
            MODIFIER: Enables usage of PROBE by Player
      * KeyCards
        - ROOM_CLASS_1
        - ROOM_CLASS_2
        - ROOM_CLASS_3
      * Probe
        - A directable android that can search independently of the
          player, but still well within their turn
      * Health Pickups
        - Player has a finite amount of health and damage from other
          players causes them to need to recover
  Movement:
    How players move around the MAP
      - Normal Round
      - Teleportaion Victim
  Alpha Infection:
    Random Attacks on Players
    Wing Shutdowns
    Location and Movement
    Teleportation Attacks
    Health


State will be stored in Agents for the players
Difficulty needs to be calculated
Define algo for using Players, Map Size, and Difficulty to determine game run time

Define SECRET CODE rules and tracking
