
squallAttack1 = {
        attackname = "squallAttack1",
        animation = "creature_attack_light",
        
        requiredWeaponType = NONE,

        range = 10,

        damageRatio = 15,

        speedRatio = 4,

        areaRange = 0,
        accuracyBonus = 0,

        healthAttackChance = 100,
        actionAttackChance = 0,
        mindAttackChance = 0,

        dotChance = 50,
        tickStrengthOfHit = 1,

        fireStrength = 0,
        fireType = 0,

        bleedingStrength = 0,
		bleedingType = 0,

        poisonStrength = 0,
        poisonType = 0,

        diseaseStrength = 100,
        diseaseType = HEALTH,
                
        knockdownChance = 0,
        postureDownChance = 0,
        postureUpChance = 0,
        dizzyChance = 0,
        blindChance = 0,
        stunChance = 0,
        intimidateChance = 0,
        
        CbtSpamBlock = "attack_block",
        CbtSpamCounter = "attack_counter",
        CbtSpamEvade = "attack_evade",
        CbtSpamHit = "attack_hit",
        CbtSpamMiss = "attack_miss",
}

AddDotPoolAttackTargetSkill(squallAttack1)

--------------------------------------------------------------------------------------
