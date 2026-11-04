/* FUN_80162b2c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162b2c  body 0x80162b2c..0x80162c2b  size 256 B
 * body sha256 df01d75e1ee21af378e8887ba97b27d0f551d1ab206b21efe308c03a32ed9742
 * provider record sha256 f35d6a95f9efd7c522e32fb15757253d3eeae5d58ac1aba3223076febdb0fcbe
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162b2c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar3;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if ((bVar1 == 2) ||
         ((bVar1 == 3 && (iVar2 = FUN_80162c2c(param_1,param_2,param_3), iVar2 != 0)))) {
        *(undefined4 *)(param_1 + 4) = 0x1000000;
        *(undefined2 *)(param_1 + 0x2b4) = 0xf;
      }
      goto LAB_80162c04;
    }
    if (bVar1 != 0) goto LAB_80162c04;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0xb000300;
    FUN_801671ec(param_1,*(byte *)(param_1 + 0x2be) + 8,
                 (int)(((uint)*(ushort *)(param_1 + 0x66) + (uint)*(ushort *)(param_1 + 0x2b6)) *
                      0x10000) >> 0x10);
  }
  cVar3 = func_0x80089d54(param_1,param_2,param_3,0x400);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
LAB_80162c04:
  FUN_80167938(param_1);
  func_0x80033648(param_1);
  return;
}
