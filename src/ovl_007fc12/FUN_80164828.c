/* FUN_80164828
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80164828  body 0x80164828..0x80164963  size 316 B
 * body sha256 3fb55288859c3df87b243ee6e4f30ad2c401d99ee4ca6ad306d27fe51e8b2f06
 * provider record sha256 f65e3025d078a9e91efc0694d582ad72bd2fcd935eda7bea6d7e45d75103adf6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164828(int param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x28c);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x100);
  if (((uVar2 < 0x514) && ((DAT_800e139f & 0x80) == 0)) &&
     (*(char *)(param_1 + 0x1a2) == DAT_800e12d2)) {
    if (((*(ushort *)(param_1 + 0x2b6) & 0x20) == 0) &&
       (iVar1 = func_0x80032fac(param_1 + 0x28,&DAT_800e1158,
                                (int)((*(ushort *)(param_1 + 0x66) + 0x100) * 0x10000) >> 0x10),
       iVar1 == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      DAT_800e139f = DAT_800e139f | 0x80;
    }
    if (((*(ushort *)(param_1 + 0x2b6) & 0x40) == 0) &&
       (iVar1 = func_0x80032fac(param_1 + 0x28,&DAT_800e1158,
                                (int)((*(ushort *)(param_1 + 0x66) - 0x100) * 0x10000) >> 0x10,0x100
                               ), iVar1 == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      DAT_800e139f = DAT_800e139f | 0x80;
    }
  }
  return;
}
