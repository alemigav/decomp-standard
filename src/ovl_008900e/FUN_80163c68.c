/* FUN_80163c68
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80163c68  body 0x80163c68..0x80163ed3  size 620 B
 * body sha256 f322387d86da93105ee2ec58e25b2d67ef029fcdc592401e75a6bb904b13c580
 * provider record sha256 ae1a48fa816a6ca57c115f47d91bd129ced351fcc00940ac40a1061c5167c9f7
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163c68(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  short sVar5;
  char cVar6;
  uint uVar4;
  undefined2 local_20;
  short local_1e;
  undefined2 local_1c;
  
  iVar2 = *(int *)(param_1 + 0x234);
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      goto LAB_80163d40;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 7) = 0;
    if ((*(ushort *)(param_1 + 0x2c8) & 2) == 0) {
      cVar6 = func_0x80036be4(param_1,6,0xf,0);
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar6;
      return;
    }
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  *(undefined4 *)(param_1 + 0x1e8) = 0x15000300;
  *(undefined1 *)(param_1 + 0x2ce) = 4;
  *(undefined2 *)(param_1 + 500) = 0;
  *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
LAB_80163d40:
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x80032dbc(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                  *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),8);
  iVar3 = func_0x8008a994(param_1,param_2,param_3,0x400);
  if (iVar3 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x10f0000;
  }
  func_0x80032b5c(param_1,0);
  cVar6 = *(char *)(param_1 + 7);
  iVar3 = *(int *)(param_1 + 0x2c4);
  *(char *)(param_1 + 7) = cVar6 + '\x01';
  if ((((*(char *)(iVar3 + 0x26f) == '\0') && (*(short *)(param_1 + 500) == 0)) &&
      ((byte)(cVar6 - 1U) < 5)) &&
     (((sVar5 = func_0x80032e74(param_1,*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x30),
                                0x154), sVar5 == 0 && (*(uint *)(param_1 + 0x28c) < 0xaf0)) &&
      (-1 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2))))) {
    *(int *)(*(int *)(param_1 + 0x2c4) + 0x250) = param_1;
    *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 4) = 0x2000000;
    cVar6 = func_0x80033144(param_1,0x800e1130);
    *(char *)(*(int *)(param_1 + 0x2c4) + 5) = *(char *)(*(int *)(param_1 + 0x2c4) + 5) + cVar6;
    local_20 = *(undefined2 *)(iVar2 + 0x1366);
    local_1e = *(short *)(iVar2 + 0x136a) + 200;
    local_1c = *(undefined2 *)(iVar2 + 0x136e);
    func_0x80037780(0x2400,0,&DAT_800e9028,&local_20);
    func_0x80052bd0(5,0);
    func_0x80052d10(0xb,200,0x28,3);
    uVar4 = func_0x80059e00(0xf,0);
    if ((uVar4 & 2) != 0) {
      _DAT_800e1134 = 0x3000000;
    }
    *(undefined1 *)(param_1 + 0x2ca) = 0x28;
    *(undefined2 *)(param_1 + 500) = 1;
  }
  return;
}
