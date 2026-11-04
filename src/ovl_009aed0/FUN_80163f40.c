/* FUN_80163f40
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80163f40  body 0x80163f40..0x8016419b  size 604 B
 * body sha256 c17056f841c40bfd691cf2432e0d39ec306b5726803b0c2f0b8a0b1e0e247526
 * provider record sha256 1e6558d75688c563543bdf3d1fd2ccd7530d0a76ca42f04d4cf7ff6fd85183df
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163f40(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 1;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if ((*(byte *)(param_1 + 0x1e9) < 0x1b) &&
     (iVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,700), iVar1 != 0)) {
    *(undefined1 *)(param_1 + 0x1e9) = 0x1b;
    *(undefined1 *)(param_1 + 0x1ea) = 0;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xfffe;
    func_0x800334c8(param_1,param_2,param_3,0);
  }
  if (*(byte *)(param_1 + 0x1e9) - 0x16 < 4) {
    local_18 = 0;
    local_16 = 0;
    local_14 = 0;
    FUN_801628f0(param_1,1,6,0x800,(int)*(short *)(param_1 + 0x66),9,&local_18);
    FUN_801628f0(param_1,1,6,0x800,(int)*(short *)(param_1 + 0x66),10,&local_18);
    FUN_801628f0(param_1,1,6,0x800,(int)*(short *)(param_1 + 0x66),0xb,&local_18);
  }
  iVar1 = func_0x80036c68(param_1,8,0xf,0);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xfffe;
  }
  iVar1 = FUN_801622f4(param_1,10,0x1b,0x21,400,(uint)_DAT_800e1266 << 1);
  if (iVar1 != 0) {
    FUN_80162d3c(param_1,(int)*(short *)(param_1 + 0x2c8),(int)*(short *)(param_1 + 0x2ca),10);
    func_0x80077d18(5,param_1);
    *(undefined2 *)(param_1 + 0x2d0) = 0;
    func_0x80052bd0(4,0);
    func_0x80052d10(0x12,0xdc,0x28,1);
    FUN_80162694(0x1e);
  }
  if (*(byte *)(param_1 + 0x1e9) < 0x14) {
    uVar2 = 0x40;
  }
  else {
    uVar2 = 0x10;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,uVar2);
  return;
}
