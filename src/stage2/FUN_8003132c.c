/* FUN_8003132c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003132c  body 0x8003132c..0x80031453  size 296 B
 * body sha256 498b30505439da9a4d966c796aa5f2207ad98af0d067003479fe998ec113cb7e
 * provider record sha256 aa65697ac3ff5b8fed0bf6ed073a786f8b1b42df0faae20ea15a8ba2b2634e73
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003132c(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x30);
  *puVar1 = &LAB_80031290;
  puVar1[2] = FUN_80031298;
  puVar1[6] = param_2;
  puVar1[1] = FUN_800311d0;
  FUN_8002d330(param_1);
  uVar4 = *(int *)(param_1 + 0x5c) * *(int *)(param_1 + 0x68);
  puVar1[8] = uVar4;
  for (; (uVar4 & 3) != 0; uVar4 = uVar4 + 1) {
  }
  puVar1[9] = uVar4;
  puVar1[10] = uVar4 - puVar1[8];
  uVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x10))
                    (param_1,1,uVar4,*(undefined4 *)(param_1 + 0x60),1);
  puVar1[7] = uVar2;
  puVar1[0xb] = 0;
  iVar3 = *(int *)(param_1 + 8);
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
  }
  uVar2 = (**(code **)(*(int *)(param_1 + 4) + 8))(param_1,1,uVar4,1);
  puVar1[4] = uVar2;
  puVar1[5] = 1;
  return;
}
