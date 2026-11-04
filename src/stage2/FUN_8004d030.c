/* FUN_8004d030
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d030  body 0x8004d030..0x8004d137  size 264 B
 * body sha256 8110ac4da3e685bc49eb5133c971ea27348f8995530fc615d96fe7750a695822
 * provider record sha256 18aa017b35320ddbea9005be49d441bc80cfd7271c56c93139fb1b2746ed6daf
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004d030(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_38;
  undefined4 local_2c;
  undefined2 local_20;
  
  puVar4 = &DAT_80113460;
  puVar5 = &DAT_8010b6c0;
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    puVar2 = (undefined4 *)*puVar5;
    FUN_8004d184((int)&local_38 + 2);
    local_20 = *puVar4;
    local_38 = CONCAT22(puVar4[1],local_20);
    puVar3 = (uint *)*puVar2;
    local_2c = local_38;
    uVar1 = *puVar3;
    uVar7 = (puVar3[3] + 1) % uVar1;
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    puVar4 = puVar4 + 3;
    if (uVar7 == puVar3[2]) {
      if (uVar1 == 0) {
        trap(0x1c00);
      }
      puVar3[2] = (uVar7 + 1) % uVar1;
    }
    puVar5 = puVar5 + 1;
    *(undefined4 *)(puVar3[3] * 4 + puVar3[1]) = local_38;
    puVar3[3] = uVar7;
  }
  return;
}
