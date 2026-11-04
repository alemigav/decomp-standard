/* FUN_80165bf8
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80165bf8  body 0x80165bf8..0x80165d8b  size 404 B
 * body sha256 92105b9a378c1e9c3c298c6df72a0367d2b66badba735d8fdeb71c4e48476872
 * provider record sha256 6bce4c3dc59f44ed60b7cb1cafbf98eaf1ecf2d5356523c9c35e4e7105fdb0ff
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165bf8(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined1 auStack_38 [32];
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x1000000;
        *(undefined1 *)(param_1 + 0x26f) = 0;
        *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = ((*(byte *)(param_1 + 5) & 1) + 3) * 0x1000000 + 0x300;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    func_0x80077adc(((*(byte *)(param_1 + 5) & 1) + 1) * 0x10000 | 0x4000001,param_1 + 0x28);
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
    local_16 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                               (int)*(short *)(_DAT_800e13f0 + 0x2a),
                               (int)*(short *)(_DAT_800e13f0 + 0x32));
    local_18 = 0;
    local_14 = 0;
    func_0x80040e58(&local_18,auStack_38);
    local_18 = 800;
    local_16 = 0;
    func_0x8004276c(auStack_38,&local_18,param_1 + 0x1e0);
  }
  cVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                          0x200);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
  *(short *)(param_1 + 0x1e4) = *(short *)(param_1 + 0x1e4) >> 1;
  return;
}
