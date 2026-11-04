/* FUN_80166550
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80166550  body 0x80166550..0x801666e3  size 404 B
 * body sha256 8b2100370e415821f630a11b28cfc4bc99f2dfccf78c307fafa6a70ba4c8e85d
 * provider record sha256 bf9e1374a7ca7f505a4408d2793cb283d1217bcfd4af698b3942bdf7825fbd9c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166550(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
        if (iVar2 != 0) {
          *(undefined1 *)((int)param_1 + 6) = 3;
          param_1[0x7a] = 0xf00;
        }
      }
      else if ((bVar1 == 3) &&
              (func_0x80089d54(param_1,param_2,param_3,0x100), *(short *)(param_1 + 0x9c) == 2)) {
        *(undefined1 *)((int)param_1 + 5) = 2;
        *(undefined2 *)((int)param_1 + 6) = 0;
      }
      goto LAB_801666c0;
    }
    if (bVar1 != 0) goto LAB_801666c0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0x2ee;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined2 *)(param_1 + 0x78) = 0;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    *param_1 = *param_1 & 0xfffffbff;
  }
  func_0x80032bd8(param_1,0,0);
  if (((int)*(short *)((int)param_1 + 0x25e) <= (int)(param_1[0xb] + 0x3b6)) &&
     (*(char *)((int)param_1 + 0x207) == '\0')) {
    func_0x80077d18(8,param_1);
    *(undefined1 *)((int)param_1 + 0x207) = 1;
    *(undefined1 *)((int)param_1 + 0x2cf) = 0x1d;
    *(undefined1 *)((int)param_1 + 0x2ce) = 10;
  }
  if ((int)*(short *)((int)param_1 + 0x25e) <= (int)(param_1[0xb] + 200)) {
    *(undefined1 *)((int)param_1 + 6) = 2;
    param_1[0x7a] = 0xe000000;
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
LAB_801666c0:
  FUN_80167c1c(param_1);
  return;
}
