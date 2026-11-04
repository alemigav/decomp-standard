/* FUN_8002df14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002df14  body 0x8002df14..0x8002e043  size 304 B
 * body sha256 d75a905cc81a7808d56b36f66dffe90d9bdea07c89261d941d66031add740f21
 * provider record sha256 3142e53e9cb44655c2cfb10ca08cee1b081de9481a7628b808955e725dd21a98
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002df14(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int param_5,
                 int *param_6,int param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = *(int *)(param_1 + 0x180);
  if (*(int *)(iVar2 + 0x24) == 0) {
    uVar3 = 2;
    if (*(uint *)(iVar2 + 0x2c) < 2) {
      uVar3 = *(uint *)(iVar2 + 0x2c);
    }
    uVar1 = param_7 - *param_6;
    if (uVar1 < uVar3) {
      uVar3 = uVar1;
    }
    local_20 = *(undefined4 *)(*param_6 * 4 + param_5);
    if (uVar3 < 2) {
      local_1c = *(undefined4 *)(iVar2 + 0x20);
      *(undefined4 *)(iVar2 + 0x24) = 1;
    }
    else {
      local_1c = *(undefined4 *)(*param_6 * 4 + param_5 + 4);
    }
    (**(code **)(iVar2 + 0xc))(param_1,param_2,*param_3,&local_20);
  }
  else {
    uVar3 = 1;
    FUN_80030f18(iVar2 + 0x20,0,param_5 + *param_6 * 4,0,1,*(undefined4 *)(iVar2 + 0x28));
    *(undefined4 *)(iVar2 + 0x24) = 0;
  }
  *param_6 = *param_6 + uVar3;
  *(uint *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) - uVar3;
  if (*(int *)(iVar2 + 0x24) == 0) {
    *param_3 = *param_3 + 1;
  }
  return;
}
