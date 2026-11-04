/* FUN_8005c03c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c03c  body 0x8005c03c..0x8005c263  size 552 B
 * body sha256 05e6f63379f27ce1a82625c064570e35e3a41e0fefe4ac424343d08e86f6dd5c
 * provider record sha256 20af58142f2b180a564fc3fc21b547965e2d2713b624ffbea7278fcc91b50cb9
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005c03c(int param_1)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  uint *puVar4;
  
  if (((*(ushort *)(param_1 + 0x1aa) & 0xfff) != 0) &&
     ((byte)(&DAT_80110f13)[*(ushort *)(param_1 + 0x1aa) & 0xfff] != 0)) {
    bVar1 = *(byte *)(param_1 + 8);
    puVar4 = (uint *)(*(int *)(param_1 + 0x234) +
                     (uint)(byte)(&DAT_80110f2c)
                                 [((byte)(&DAT_80110f13)[*(ushort *)(param_1 + 0x1aa) & 0xfff] - 1)
                                  * 6] * 0x178);
    if ((bVar1 & 1) != 0) {
      puVar4 = puVar4 + 0x178;
    }
    if ((bVar1 == 0xe) || (bVar1 == 0x41)) {
      puVar4 = puVar4 + 0x5e;
    }
    if ((*puVar4 & 1) != 0) {
      sVar2 = *(short *)(puVar4 + 0x47);
      *(short *)(puVar4 + 0x47) = sVar2 + 0x14;
      uVar3 = puVar4[0x14] + (int)(short)(sVar2 + 0x14);
      puVar4[0x14] = uVar3;
      if ((int)*(short *)(puVar4 + 10) < (int)uVar3) {
        if (*(char *)((int)puVar4 + 0x111) == '\0') {
          *puVar4 = *puVar4 & 0xfffffffe;
        }
        else {
          puVar4[0x14] = (int)*(short *)(puVar4 + 10);
          *(short *)(puVar4 + 0x47) =
               -(short)(((int)((uint)*(ushort *)(puVar4 + 0x47) << 0x10) >> 0x10) -
                        ((int)((uint)*(ushort *)(puVar4 + 0x47) << 0x10) >> 0x1f) >> 1);
          *(char *)((int)puVar4 + 0x111) = *(char *)((int)puVar4 + 0x111) + -1;
          if (((*(ushort *)((int)puVar4 + 0x11e) & 2) != 0) &&
             (uVar3 = FUN_80033604(), (uVar3 & 1) != 0)) {
            *(short *)((int)puVar4 + 0x2a) = -*(short *)((int)puVar4 + 0x2a);
            *(short *)(puVar4 + 0xb) = -*(short *)(puVar4 + 0xb);
          }
          FUN_80077adc(0x10e0001,puVar4 + 0x13);
        }
      }
      if (*(char *)((int)puVar4 + 0x111) != '\0') {
        if ((*(ushort *)((int)puVar4 + 0x11e) & 1) != 0) {
          *(undefined2 *)(puVar4 + 0x16) = 0x100;
          FUN_80040e58(puVar4 + 0x16,puVar4 + 2);
          FUN_80040cf4(puVar4 + 2,puVar4 + 0xe);
          puVar4[0x13] = puVar4[0x13] + (int)*(short *)((int)puVar4 + 0x2a);
          puVar4[0x15] = puVar4[0x15] + (int)*(short *)(puVar4 + 0xb);
        }
        if (*(char *)((int)puVar4 + 0x111) != '\0') {
          return;
        }
      }
      *(undefined2 *)(puVar4 + 0x16) = 0x100;
      FUN_80040e58(puVar4 + 0x16,puVar4 + 2);
      FUN_80040cf4(puVar4 + 2,puVar4 + 0xe);
      puVar4[0x13] = puVar4[0x13] + (int)*(short *)((int)puVar4 + 0x2a);
      puVar4[0x15] = puVar4[0x15] + (int)*(short *)(puVar4 + 0xb);
    }
  }
  return;
}
