/* FUN_800a5018
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5018  body 0x800a5018..0x800a517f  size 360 B
 * body sha256 55702f524b277af68337cfbcbc8ae5fe6fb02e647b6d823b7642d5948d860e70
 * provider record sha256 b8a1f540d46ae1dc70b765f95e5f6996e97c152f86980ec0cc0948fbc15b770f
 * callees 7 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800a5018(undefined4 *param_1,undefined2 param_2,undefined2 param_3,uint param_4)

{
  undefined1 uVar1;
  
  DAT_80143f08 = 0;
  FUN_800a5794();
  DAT_80143fe8 = (byte)(param_4 >> 0x14) & 1;
  DAT_80143e90 = 1;
  osCreateMesgQueue(0x80143e60,0x80143e80,4);
  osSetEventMesg(6,0x80143e60,&DAT_80143e90);
  _DAT_80143f04 = func_0x800113e0(*param_1);
  *param_1 = _DAT_80143f04;
  _DAT_80143e50 = (*_DAT_80144008)(0x400,0x80);
  osCreateThread(0x80143ca0,0,FUN_800a2560,0,_DAT_80143e50 + 0x400,0x7a);
  osStartThread(0x80143ca0);
  uVar1 = 2;
  if ((((param_4 & 0x10000) == 0) && (uVar1 = 3, (param_4 & 0x20000) == 0)) &&
     (uVar1 = 4, (param_4 & 0x40000) == 0)) {
    uVar1 = (param_4 & 0x80000) == 0;
  }
  FUN_800a4dc4(param_1,param_2,param_3,uVar1);
  return 0;
}
