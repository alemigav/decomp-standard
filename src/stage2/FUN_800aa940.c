/* FUN_800aa940
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa940  body 0x800aa940..0x800aab43  size 516 B
 * body sha256 04d070ae675eb162d30c1705adc88eed39397bb7ae65b3698abf1d35899578e1
 * provider record sha256 b308d2f89c0b1376c31ae17c7edfa31fbc58e44760edd4ee60fb1ddfb94ecfd8
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_800aa940(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,ushort param_7,byte param_8,byte param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38 [2];
  
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    puVar4 = param_1;
    if (param_1 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)&DAT_801484e0;
    }
    puVar4[2] = param_6;
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    puVar4[3] = *param_2;
    puVar4[4] = uVar2;
    puVar4[5] = uVar3;
    uVar2 = param_3[1];
    uVar3 = param_3[2];
    puVar4[6] = *param_3;
    puVar4[7] = uVar2;
    puVar4[8] = uVar3;
    puVar4[9] = param_4;
    *(ushort *)(puVar4 + 0xf) = param_7;
    puVar4[0xe] = param_7 | 0x80000000;
    puVar4[0xc] = param_5;
    puVar4[10] = (float)param_8 / 127.0;
    puVar4[0xb] = (float)param_9 / 127.0;
    if (param_1 == (undefined4 *)0x0) {
      FUN_800a9600(puVar4,&local_48,&local_44,&local_40,&local_3c,local_38);
      if (local_48 != 0.0) {
        iVar1 = FUN_800b2298(*(undefined2 *)(puVar4 + 0xf),0x7f,0x40);
        puVar4[0xd] = iVar1;
        if (iVar1 != -1) {
          FUN_800a9a98(puVar4,local_48,local_40,local_3c,local_38[0],local_44);
          FUN_800a56c0();
          return puVar4[0xd];
        }
      }
    }
    else {
      *puVar4 = _DAT_80148bd4;
      if (_DAT_80148bd4 != (undefined4 *)0x0) {
        _DAT_80148bd4[1] = puVar4;
      }
      puVar4[0xd] = 0xffffffff;
      _DAT_80148bd4 = puVar4;
      puVar4[1] = 0;
      *(undefined2 *)((int)puVar4 + 0x3e) = 0;
      puVar4[2] = puVar4[2] | 0x30000;
    }
    FUN_800a56c0();
  }
  return 0xffffffff;
}
