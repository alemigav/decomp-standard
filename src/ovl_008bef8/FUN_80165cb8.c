/* FUN_80165cb8
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165cb8  body 0x80165cb8..0x80165dc3  size 268 B
 * body sha256 50aa4e5d3121e329180b13cb4f75fac0cef594b9f6e6f6dbde4ee9883029d396
 * provider record sha256 0c8f9dbc97128756a59b954154d2d57cde6f2db5b5523ba10f5f2822e230640d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165cb8(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x234);
  if (*(char *)(param_1 + 0x2cd) == '\0') {
    DAT_8016636c = &DAT_80166254;
    *(code **)(param_1 + 0x2d0) = FUN_80165cb8;
    *(char *)(param_1 + 0x2cd) = *(char *)(param_1 + 0x2cd) + '\x01';
  }
  else {
    do {
      if ((*(ushort *)(DAT_8016636c + 10) & 2) == 0) {
        uVar2 = *(ushort *)(DAT_8016636c + 8);
        uVar3 = func_0x80033604();
        func_0x80037780((uVar3 & 0xff) * 2 + 0x1800 | 0x6000000,0,iVar4 + (uint)uVar2 * 0x178 + 0x38
                        ,DAT_8016636c);
      }
      puVar1 = (ushort *)(DAT_8016636c + 10);
      DAT_8016636c = DAT_8016636c + 0xc;
    } while ((*puVar1 & 1) != 0);
    if (*(char *)(param_1 + 0x2cd) == '\x18') {
      *(undefined4 *)(param_1 + 0x2d0) = 0;
    }
    *(char *)(param_1 + 0x2cd) = *(char *)(param_1 + 0x2cd) + '\x01';
  }
  return;
}
