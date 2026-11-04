/* FUN_800b4dc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4dc0  body 0x800b4dc0..0x800b4fd7  size 536 B
 * body sha256 478d334656be01e3d0df882cb7b964958e15f3ce4706bbc530497337ac7e913f
 * provider record sha256 e6658d15e7e82f617a849c746cbd3130fd9122b845e98fab5a01ebdfb16e506c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b4dc0(int param_1,short *param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined2 *puVar4;
  
  sVar1 = param_2[2];
  puVar4 = (undefined2 *)(param_1 + *(short *)(param_1 + 0x188) * 0x10 + 0x168);
  sVar2 = param_2[1];
  *puVar4 = (short)(((*param_2 + -0x20) * 0xcccc00 + 0x4000 >> 0xf) << 1);
  puVar4[1] = (short)(((sVar2 + -0x20) * 0xcccc00 + 0x4000 >> 0xf) << 1);
  sVar2 = param_2[3];
  sVar3 = param_2[4];
  puVar4[2] = (short)(((sVar1 * 0x400 + -0x5000) * 0x3333 + 0x4000 >> 0xf) << 1);
  puVar4[3] = (short)(((sVar2 * 0x400 + -0x2c00) * 0x3333 + 0x4000 >> 0xf) << 1);
  sVar1 = param_2[5];
  puVar4[4] = (short)(((sVar3 * 0x400 + -0x20bc) * 0x4b17 + 0x4000 >> 0xf) << 1);
  sVar2 = param_2[6];
  puVar4[5] = (short)(((sVar1 * 0x400 + -0x1200) * 0x4444 + 0x4000 >> 0xf) << 1);
  sVar1 = param_2[7];
  puVar4[6] = (short)((((sVar2 + -4) * 0x400 + 0x2aa) * 0x7ade + 0x4000 >> 0xf) << 1);
  puVar4[7] = (short)(((sVar1 * 0x400 + -0x710) * 0x740c + 0x4000 >> 0xf) << 1);
  FUN_800b6634(param_1,param_3,param_4);
  *(ushort *)(param_1 + 0x188) = *(ushort *)(param_1 + 0x188) ^ 1;
  return;
}
