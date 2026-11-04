/* FUN_80162630
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162630  body 0x80162630..0x80162703  size 212 B
 * body sha256 9d7ee6c03251ae2751716c748fe717ca2313188d7609469fa8197d514c965021
 * provider record sha256 de6d3474ad1ab266cd4a5d02f4793f6cddebb8c61d3476b7f45667e50d16bf08
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162630(int param_1)

{
  short sVar1;
  
  sVar1 = func_0x80033024(&DAT_800e1158,
                          *(int *)(param_1 + 0x234) +
                          (uint)(byte)(&DAT_80163022)[(*(ushort *)(param_1 + 0x1aa) & 1) * 7] *
                          0x178 + 0x4c,600);
  if (((sVar1 != 0) && (4 < *(byte *)(param_1 + 0x1e9))) && (_DAT_800e1128 == 0)) {
    if ((DAT_800e139f & 0x80) == 0) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
      DAT_800e139f = DAT_800e139f | 0x80;
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0x1060000;
    }
  }
  return;
}
