/* FUN_80165364
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80165364  body 0x80165364..0x80165423  size 192 B
 * body sha256 489cadb0456c0d5a0fddefd925a314dfc7838aeab36c215648f7968f7c33520c
 * provider record sha256 01d6e523462e91998f153223592ef7470b475940bbe5687a936da3e76fe93eb3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165364(int param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x28c);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200);
  if ((((sVar1 == 0) && (uVar2 < 0x514)) && ((DAT_800e139f & 0x80) == 0)) &&
     (((*(ushort *)(param_1 + 0x1f0) & 0x800) != 0 && (*(char *)(param_1 + 0x1a2) == DAT_800e12d2)))
     ) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    DAT_800e139f = DAT_800e139f | 0x80;
  }
  return;
}
