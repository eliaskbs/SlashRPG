#pragma once


UENUM( BlueprintType )
enum class ECharacterState: uint8
{
	ECS_Unequipped UMETA(DisplayName="Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName="EquippedOneHandedWeapon"),
	ECS_EquippedTwoHandedWeapon UMETA(DisplayName="EquippedTwoHandedWeapon")
	
};

UENUM( BlueprintType )
enum class EActionState: uint8
{
	EAS_Unoccupied UMETA(DisplayName="Unequipped"),
	EAS_Attacking UMETA(DisplayName="Attacking"),
	EAS_EquippinWeapon UMETA(DisplayName="EquippingWeapon")
};