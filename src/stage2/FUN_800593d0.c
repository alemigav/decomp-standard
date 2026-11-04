/* FUN_800593d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800593d0  body 0x800593d0..0x8005952f  size 352 B
 * body sha256 3648700d07ff8656ffbd5ac90f655fafa797a6722679e068170f04fe8a13b988
 * provider record sha256 ee4810c26a8b7f0767f200a8c3df324d25b6b92673ef3d80d84e5e9ec38bee9a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800593d0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        FUN_800551e0();
        param_1[1] = 0x1000000;
        *(undefined1 *)((int)param_1 + 0x26f) = 0;
        *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xed;
        *(ushort *)(param_1 + 0x7c) = *(ushort *)(param_1 + 0x7c) | 2;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x79) = 0;
    param_1[0x7a] = ((*(byte *)((int)param_1 + 5) & 1) + 3) * 0x1000000 + 0x300;
    param_1[0x78] = (*(byte *)((int)param_1 + 5) & 1) * 400 - 200;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    FUN_80077adc(((*(byte *)((int)param_1 + 5) & 1) + 1) * 0x10000 | 0x4000001,param_1 + 10);
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
    *param_1 = *param_1 & 0xfffffffb;
  }
  if (*(char *)((int)param_1 + 0x1ea) != '\0') {
    FUN_80032b5c(param_1,0);
  }
  cVar2 = FUN_80089d54(param_1,param_2,param_3,0x400);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
  return;
}
