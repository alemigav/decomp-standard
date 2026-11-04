/* FUN_801626ac
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801626ac  body 0x801626ac..0x80162947  size 668 B
 * body sha256 5671432c8ead4781f911e59ef516cf722184a81946e46c5e78049c1190ad7a3e
 * provider record sha256 417bf8cbb65463fe4cd888b33a962b58994601fac163a56ca57107779f544320
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801626ac(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  undefined1 *puVar3;
  
  if (*(char *)(param_1 + 0xad) == '\0') {
    puVar3 = &DAT_800e1130;
  }
  else {
    puVar3 = _DAT_800e13ec;
  }
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 == 1) {
    func_0x800653d0(param_1,puVar3 + 0x28,0,0);
    sVar2 = FUN_80166d64(param_1,(int)*(short *)(param_1 + 0x98),
                         (int)*(short *)((int)param_1 + 0x262),6);
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + sVar2;
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x40);
    func_0x80032b5c(param_1,0);
    if (*(char *)((int)param_1 + 0x2bf) == '\0') {
      *(undefined1 *)((int)param_1 + 6) = 2;
    }
    if (0x78 < *(byte *)((int)param_1 + 0x2c9)) {
      *(undefined1 *)((int)param_1 + 5) = 3;
      *(undefined2 *)((int)param_1 + 6) = 0;
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) goto LAB_80162924;
      if (*(short *)((int)param_1 + 0x1aa) == 0x6002) {
        if (*(short *)(param_1 + 0x9c) == 0) {
          return;
        }
        *(undefined2 *)((int)param_1 + 0x1aa) = 2;
      }
      *(undefined1 *)((int)param_1 + 6) = 1;
      param_1[0x7a] = ((uint)*(byte *)((int)param_1 + 0x2cd) * 0xd + 1) * 0x1000000 + 0x3f00;
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x40);
      *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfd;
      *(undefined1 *)((int)param_1 + 0x2c1) = 3;
      *(undefined1 *)((int)param_1 + 0x2c3) = 3;
      _DAT_800e1128 = _DAT_800e1128 & 0xffbf;
      *param_1 = *param_1 & 0xfffffffb;
      *(undefined1 *)((int)param_1 + 0x2b6) = 0;
    }
    else {
      if (bVar1 == 2) {
        *(undefined1 *)((int)param_1 + 6) = 3;
        *(undefined2 *)(param_1 + 0x7d) = 0x5a;
      }
      else if (bVar1 != 3) goto LAB_80162924;
      func_0x800653d0(param_1,puVar3 + 0x28,0,0);
      sVar2 = FUN_80166d64(param_1,(int)*(short *)(param_1 + 0x98),
                           (int)*(short *)((int)param_1 + 0x262),6);
      *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + sVar2;
      *(undefined1 *)(param_1 + 0xaf) = 0;
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x40);
      sVar2 = *(short *)(param_1 + 0x7d);
      *(short *)(param_1 + 0x7d) = sVar2 + -1;
      if (sVar2 != 1) goto LAB_80162924;
      *(undefined1 *)((int)param_1 + 6) = 1;
    }
    *(undefined1 *)((int)param_1 + 0x2c9) = 0;
  }
LAB_80162924:
  FUN_80162948(param_1);
  return;
}
