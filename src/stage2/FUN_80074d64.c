/* FUN_80074d64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074d64  body 0x80074d64..0x80074e83  size 288 B
 * body sha256 56066e806e3b793fc8d426b5fe8476bce8ee2e4aae7d8ce833654fba0e798a3f
 * provider record sha256 03b58222e4296a07367f33212102ea854598635ff00fc2e918a7e6272700fc55
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80074d64(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 auStack_30 [4];
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  
  uVar6 = (uint)DAT_800e8604;
  uVar4 = 0;
  local_3c = 0;
  if (uVar6 != 0) {
    puVar5 = &DAT_800c76b0;
    local_40 = param_1;
    local_38 = param_2;
    do {
      pcVar3 = (char *)puVar5[0x612c];
      puVar5 = puVar5 + 1;
      if ((pcVar3 == (char *)0x0) || (uVar4 = uVar4 + 1, *pcVar3 != '\a')) {
        bVar1 = uVar4 < uVar6;
      }
      else if ((pcVar3[1] & 0x80U) == 0) {
        iVar2 = FUN_80083e14(&local_40,pcVar3 + 4);
        bVar1 = uVar4 < uVar6;
        if (iVar2 != 0) {
          return (int)*(short *)(pcVar3 + 0xc);
        }
      }
      else {
        local_2c = *(undefined2 *)(pcVar3 + 4);
        local_2a = *(undefined2 *)(pcVar3 + 6);
        local_28 = *(undefined2 *)(pcVar3 + 8);
        local_26 = *(undefined2 *)(pcVar3 + 10);
        local_24 = *(undefined2 *)(pcVar3 + 0xc);
        local_22 = *(undefined2 *)(pcVar3 + 0xe);
        local_20 = *(undefined2 *)(pcVar3 + 0x10);
        local_1e = *(undefined2 *)(pcVar3 + 0x12);
        iVar2 = FUN_80083d2c(&local_40,auStack_30);
        bVar1 = uVar4 < uVar6;
        if (iVar2 != 0) {
          return (int)*(short *)(pcVar3 + 0x14);
        }
      }
    } while (bVar1);
  }
  return 0;
}
