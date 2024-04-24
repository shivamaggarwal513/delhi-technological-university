import tensorflow as tf
import logging

tf.get_logger().setLevel(logging.ERROR)


def get_imdb_dataset(max_len, num_words):
    (X_train, y_train), (X_test, y_test) = tf.keras.datasets.imdb.load_data(num_words=num_words)
    
    X_train = tf.keras.preprocessing.sequence.pad_sequences(X_train, maxlen=max_len)
    X_test = tf.keras.preprocessing.sequence.pad_sequences(X_test, maxlen=max_len)
    
    return (X_train, y_train), (X_test, y_test)


def get_attention_model(max_len, num_words):
    inputs = tf.keras.layers.Input((max_len,))
    embedding_output = tf.keras.layers.Embedding(num_words, 128)(inputs)
    attention_output = tf.keras.layers.MultiHeadAttention(num_heads=8, key_dim=16)(embedding_output, embedding_output)
    pooling_output = tf.keras.layers.GlobalAveragePooling1D()(attention_output)
    outputs = tf.keras.layers.Dense(1, activation='sigmoid')(pooling_output)
    
    model = tf.keras.Model(inputs=inputs, outputs=outputs, name='Attention')
    
    model.compile(
        optimizer = tf.keras.optimizers.Adam(),
        loss = tf.keras.losses.BinaryCrossentropy(),
        metrics = ['accuracy']
    )
    
    return model


def main():
    VOCAB_SIZE = 10000
    MAX_LEN = 128
    
    (X_train, y_train), (X_test, y_test) = get_imdb_dataset(MAX_LEN, VOCAB_SIZE)
    
    print(f'X_train: {X_train.shape}')
    print(f'Y_train: {y_train.shape}')
    print(f'X_test : {X_test.shape}')
    print(f'Y_test : {y_test.shape}\n')
    
    BATCH_SIZE = 128
    EPOCHS = 5
    
    model = get_attention_model(MAX_LEN, VOCAB_SIZE)
    print(model.summary())
    
    print('\nTraining Attention Model\n')
    model.fit(X_train, y_train, batch_size=BATCH_SIZE, epochs=EPOCHS, validation_split=0.2)
    
    print(f'\nPerformance on test set: {model.evaluate(X_test, y_test, verbose=0)}')


if __name__ == '__main__':
    main()
