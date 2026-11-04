/* FUN_8006e1bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e1bc  body 0x8006e1bc..0x8006e26f  size 180 B
 * body sha256 94e0f4d29127e182cb3e3bed34a0e7fa50fffd346e9e2135b616b43a73ccfd34
 * provider record sha256 6f74a80284303c6434affbc073239c9030d797c3bc680c4264d653fb00d53d5e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8006e1bc(int param_1,byte *param_2,uint param_3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  
  uVar2 = (*(code *)(&PTR_LAB_80113898)[*param_2])();
  pbVar4 = *(byte **)(param_1 + 0x1c);
  while (pbVar4 != param_2 + (param_3 & 0xff)) {
    sVar1 = *(short *)pbVar4;
    *(byte **)(param_1 + 0x1c) = pbVar4 + 2;
    uVar3 = (*(code *)(&PTR_LAB_80113898)[pbVar4[2]])(param_1);
    pbVar4 = *(byte **)(param_1 + 0x1c);
    if (sVar1 == 0) {
      uVar2 = uVar2 & uVar3;
    }
    else {
      uVar2 = uVar2 | uVar3;
    }
  }
  return uVar2;
}
