# JoyWayTest
First of all. I appologise for codestyle - I use codestyle, which used previously, not UE default

# Short Overview:
# On CPP side:
Pickable Item - base Actor Component, describing that item is pickable.
Picker - Actor Component, which adds functioality for picking items.

I_Gun - Interface for damaging.
Destructable - Actor Component for getting damage.
Projectile Damage and Hitscan Damage - its implementations.
Simple Damage - base damage type used for damaging.

Gun Inventory - Actor Component for collecting Guns.

Pickable Gun - Pickable Item child, which adds into Gun Inventory on picking.

Character Gun Inventory - Gun Inventory child, which notify character about changing weapon.

JoyWayTestCharacter and JoyWayTestProjectile are cleaned up and changed to damage and change weapons.

There is also Weapon class to show example of combing weapons together.

# On BP side:
BP/Items contains set of interactale items. Cuse doesn't have damage, Blue Gun use Projectile damage, other Guns - HitScan damage.
Yellow cube is used to check damage.
BP/Picker and BP/PickerUI is used to show primitive UI of interacting and capture input.
BP/DamageArea is used for damaging character.
Character also contains respawn logic.

# Teleport:
Switch between levels implemented via Seamless Travelling. Teleport starts travelling, GameMode specifies, what classes should be moved, Unposes character to prevent force deletion, saves character in GameInstance and Posses character to the new Player Controller. Note that method, which specifies what actor should be saved and method, which finalise travelling are called from different GameModes (first is called from source map GameMode, second from destination map GameMode), so GameInstance is used to save data.
I also tried to persist character via PlayerController, but finalisation of Player Controller is called before it creates new character and Posses to it
Note, that only ClientTravel is allowed for PIE Seamless Travelling

# Controls:
LMD to shoot, E to interact, 1 / 2 to switch between first and second weapons
