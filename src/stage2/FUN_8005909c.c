/* FUN_8005909c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005909c  body 0x8005909c..0x8005925b  size 448 B
 * body sha256 25371b09fa7823562197e5d4c6d687251b002f89dbd2d50ab441e65e7163018b
 * provider record sha256 8d28086999de3f24898069e992412b78e3987283e733d879823ce75979e38a53
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005909c(int param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  undefined1 auStack_10 [8];
  
  FUN_80082200(auStack_10,0,8);
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        FUN_800334c8(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0);
        FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200
                    );
        sVar4 = *(short *)(param_1 + 500) + -1;
        *(short *)(param_1 + 500) = sVar4;
        if (sVar4 == -1) {
          FUN_800551e0(param_1);
          *(undefined4 *)(param_1 + 4) = 0x1000000;
        }
        FUN_80032b5c(param_1,0);
      }
      goto LAB_800591fc;
    }
    if (bVar1 != 0) goto LAB_800591fc;
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined1 *)(param_1 + 6) = 1;
    DAT_800e110c = DAT_800e110c | 0x40;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  }
  uVar2 = *(ushort *)(param_1 + 0x66);
  if ((uVar2 & 0x200) == 0) {
    uVar3 = -(uVar2 >> 2 & 0xff);
  }
  else {
    uVar3 = uVar2 >> 2 & 0xff;
  }
  *(ushort *)(param_1 + 0x66) = uVar2 + uVar3;
  if ((*(ushort *)(param_1 + 0x66) & 0x3e0) == 0) {
    *(ushort *)(param_1 + 0x66) = *(ushort *)(param_1 + 0x66) & 0xff00;
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 500) = 0x2d;
  }
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
LAB_800591fc:
  if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
    DAT_800e112a = DAT_800e112a | 2;
  }
  return;
}
