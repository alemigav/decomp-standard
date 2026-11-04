/* FUN_800310b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800310b0  body 0x800310b0..0x800311c3  size 276 B
 * body sha256 d0f025435134e28fde5aae1431de0f072455b80a794bfc8768400b9e00d2a4f1
 * provider record sha256 1472425f42006476fa6a4915c461faf53b0344c850bc0b0eb81e48ebb503d80e
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800310b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_228 [24];
  uint local_1c8;
  uint local_1b0;
  undefined1 auStack_98 [120];
  undefined *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = func_0x80004c9c(param_2);
  uVar2 = 1;
  if (iVar1 != 0) {
    local_228[0] = FUN_8002e890(auStack_98);
    FUN_80028450(local_228);
    local_20 = &DAT_800b85a8;
    local_1c = 1000;
    local_18 = 0x413;
    FUN_80028510(local_228,0xfe,FUN_80031050);
    FUN_80028f04(local_228,param_2);
    FUN_80028780(local_228,1);
    iVar1 = FUN_8003132c(local_228,0);
    *(undefined4 *)(iVar1 + 0xc) = param_1;
    FUN_800288c0(local_228);
    while (local_1b0 < local_1c8) {
      uVar2 = FUN_80028a20(local_228,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
      (**(code **)(iVar1 + 4))(local_228,iVar1,uVar2);
    }
    (**(code **)(iVar1 + 8))(local_228,iVar1);
    FUN_80028c58(local_228);
    FUN_800284f4(local_228);
    uVar2 = 0;
  }
  return uVar2;
}
