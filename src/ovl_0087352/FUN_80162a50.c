/* FUN_80162a50
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80162a50  body 0x80162a50..0x80162c3f  size 496 B
 * body sha256 c49c150b74a16730f3e9c5cbbb453ca29fb2045dd63ab91ea3e2b8a0fccbd9b3
 * provider record sha256 e8015c7b88d15b2d70ca76347ead00c205031b25e96adc688f726ed71f6875eb
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162a50(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  ushort uVar4;
  int iVar3;
  char cVar5;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 == 1) {
    *param_1 = *param_1 & 0xfffffff7;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 0x78) = uVar4 & 7 | 0x50;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0x50;
    *(undefined1 *)((int)param_1 + 0x2b5) = 0xff;
    *(undefined1 *)((int)param_1 + 0x2b6) = 0x20;
    *(undefined1 *)((int)param_1 + 6) = 2;
  }
  else if (bVar1 < 2) {
    if (bVar1 != 0) {
      return;
    }
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xffbf;
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) != 0) {
      func_0x80077d18(1,param_1);
    }
    uVar2 = func_0x80033604();
    param_1[0x7a] = (uVar2 & 7) * 0x10000 + 0x6000700;
    *(undefined1 *)((int)param_1 + 0x2b9) = 0;
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 0x78) = (uVar4 & 7) + 0x3c;
    *(undefined1 *)((int)param_1 + 0x2b5) = 0xc;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *(undefined1 *)((int)param_1 + 0x2b6) = 0;
    *(undefined1 *)(param_1 + 0xad) = 1;
    *(undefined1 *)((int)param_1 + 6) = 2;
    *(ushort *)((int)param_1 + 0x2c6) = *(ushort *)((int)param_1 + 0x2c6) | 1;
  }
  else if (bVar1 != 2) {
    if (bVar1 == 3) {
      FUN_80165c68(param_1,4);
      return;
    }
    return;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,*(undefined1 *)((int)param_1 + 0x2b6));
  func_0x80032bd8(param_1,0,0);
  if (*(short *)(param_1 + 0x78) < 300) {
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + 1;
  }
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar3 != 0) {
    *(undefined1 *)((int)param_1 + 6) = 3;
  }
  cVar5 = *(char *)((int)param_1 + 0x2b5) + -1;
  *(char *)((int)param_1 + 0x2b5) = cVar5;
  if (cVar5 == -1) {
    *(undefined1 *)((int)param_1 + 6) = *(undefined1 *)(param_1 + 0xad);
  }
  return;
}
