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

# Partitially implemented:
I tried to create switching between levels via Seamless Travel feature. It works, but I stuck into a problem with camera and Axis Mapping and Continue work later

# Controls:
LMD to shoot, E to interact, 1 / 2 to switch between first and second weapons
